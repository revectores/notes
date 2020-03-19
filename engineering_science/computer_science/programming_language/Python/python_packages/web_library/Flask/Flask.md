# Flask Basis

### 1. A Quick Overview

```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
	return "Hello World!"

if __name__ == '__main__':
    app.run()
```

After executing this program, a built-in web server of flask will be actived in `127.0.0.1:5000`, which includes that how "micro" the framework is.

Now let's check the structure of the program. First we create a `Flask` object `app`, which uses the `__name__` of program as parameter(why?), then `@route` decorator tell creates the mapping between path and the content. In this case, the root path is mapped to the words "Hello World!". After these preparation are done. We use `app.run()` method to actually makes the WSGI (Web Server Gateway Interface) application alive.



### 2. Deploy & Configuration

##### # local CLI pathway

Besides writing in the code, We can use the CLI tool (like bash) to run the object like this:

```bash
# bash
FLASK_APP="app.py"
flask run
```

Some other configuration can also be set through this way:

```bash
# bash
FLASK_ENV="development"
FLASK_DEBUG=0
```

`ENV` tells the application to deploy in development or production mode, different authorization are applied in two mode, if and only if the mode at dev status, `DEBUG` can be activated.

By default the ip address and port are set as `127.0.0.1:5000`, the localhost which is not accessible to the network, to make it accessible we can manually set it to`0.0.0.0` by `--host` parameter:

```bash
# bash
flask run --host=0.0.0.0
```



##### # Industrial Pathway

The fact is `run` method (no matter code way or CLI way) is not the standard method and usually deprecated in production because the bad proformance. When actually deployed in server side, the common way is use `nginx`, `gunicorn`, or some other web solutions.





### 3. Parameters

##### 3.1 Routing

Decorator is used to create the create route mapping, parameter in the path can be injected through `<var>` format:

```python
@app.route('/user/<username>')
def user(username):
	return "hello, {username}".format(username=username)
```

The bottom mechanism about decorator is explained at Python Cookbook.

And more specific, you can contorl the type of parameter:

```python
@app.route('/user/<string:username>')
@app.route('/number/<int:number>')
```

The type includes `string`, `path`, `int`, `float`, and `uuid`.

##### 3.2 Request Method

By default only `GET` method is allowed to a path, the allowed methods can be set as another decorator parameter:

```python
from flask import request

@app.route('/method', methods=['GET', 'POST', 'PUT'])
def method(){
	# reqeust object stores method info
 	return "This is a {method} message.".format(method=request.method)
}
```

e.g. the login path usually both shows the login form and receives the form post, this is usually constructed as:

```python
@app.route('/login', methods=['GET', 'POST'])
def login(){
  if request.method == 'GET':
  	return login_check()
  else:  # Flask will block any other request method besides allowed.
  			 # Well anyway this is still not the best practice to SE XD.
  	return show_the_login_form()
}
```

##### 3.3 Request Parameters

The parameters passed by `POST` and `GET` are also stored in the `request` object as `request.form` and `request.args` dictionary respectively:

```python
@app.route('/login', method=['GET', 'POST'])
def login():
  payload = request.form if request.method=='POST' else request.args
	is_valid = login_check(payload['username'], payload['password'])  
  return user_page() if valid else "access denied"
# This is only for explaination purpose, in practice we usually not process the GET parameters and POST form as the same...
```



### 4. Rendering Templates

Use the `render_template` method to render page from template instead of build the `html` page manually, the template file stores in folder `templates`.

```jinja2
<!-- user.html -->
<!doctype html>
<title>user page</title>
{% if username %}
	Hello, {{ username }}!
{% else %}
	Hello, World!
{% endif %}
```

```python
@app.route('/user/<username>')
def user(username):
	return render_template('user.html', username=username)
```



### 5. Response Object

For the most simple case we just return a string (`render_templates` also just render a page content to a string, you can check its type to confirm this). While the response is more than just contents, as the request, it also includes the header, and status code, so we need a `response` object instead of only built-in string. In the simple returned string case,  flask converts the string into `response` object automatically, and add `200` status with no header.

Once further control is required, you can create a response object manually:

```python
from flask import make_response

@app.route('/user')
def user():
	resp = make_response(render_template('user.html'), 200, {'header-x': 1})
	resp.headers['header-y'] = 2
	return resp
```





### 6. URL Redirection

##### 6.1. Slash Behavior

The behavior about request to ending slash is a little tricky, basically, you can achieve a "folder" by consider it as a "file", which means you can get a slash-end url by accessing it without ending slash, at this time a 308 redirection appeared. The reverse approach is not allowed.

(If two kinds of url are both supported this is never happened)

```python
@app.route('/slash/')
def slash():
  return "this is a slash page!"
```

```requests
# http://localhost:5000/slash
127.0.0.1 - - [19/May/2019 12:42:05] "GET /slash HTTP/1.1" 308 -
127.0.0.1 - - [19/May/2019 12:42:05] "GET /slash/ HTTP/1.1" 200 -

# http://localhost:5000/slash/
127.0.0.1 - - [19/May/2019 12:56:06] "GET /slash/ HTTP/1.1" 200 -
```

If you try to access a unslash path with slash, `404 Not Found` is waitting for you:

```python
@app.route('/slash')
def unslash():
  return "this is a not slash page!"
```



##### 6.2 Redirection

`redirect` methods are required to do the redirection.

```python
from flask import redirect

@app.route('/')
def index():
  return "This is the index page!"

@app.route('/re')
def re():
	return redirect('/')
```

Usually the `redirect` method is used together with `url_for ` method, which maps the function name and parameters to url.

##### 6.3 URL Building

```python
from flask import url_for

@app.route('/')
def index():
  return "You are in the index page!"


@app.route('/para/<num>')
def some_num(num):
	return "your input num is %s" % num


with app.test_request_context():
  print(url_for('index'))										# /
  print(url_for('index', next='next'))			# /?next=next
  # More para is allowed, the unknown keys will be the url parameters.
  
  # print(url_for('some_num'))
  # Less para is not allowed, the existed parameter must be specified.
  
  print(url_for('some_num', num='123'))			# /para/123
  print(url_for('some_num', num='123', str='hello'))	# /para/123?str=hello
```

To create url for static files, the special `filename` parameter is required:

```python
url_for('static', filename="style.css")
```



### 7. Cookies and Sessions

##### 7.1. Cookies

You can get/set cookies from request/response object:

```python
# Setter
@app.route('/set-name')
def set_name():
  resp = make_response('set name sucessful!')
  resp.set_cookie('name', 'Robert')
 	return resp
```

```python
# Getter
@app.route('/get-name')
def get_name():
	name = request.cookies.get('name')
  return "You name is %s!" % name
```



##### 7.2. Session

Session is bulit on the cookies mechanism with crypto technique appied to identify the user securely. The info you want to store will be encrypted to a string and stored at one cookie item named session, so the infomation can be stored in user side to show its identification but only server knows its content.

```python
from flask import escape, url_for, redirect

# session mechanism don't rely on asymmetric entryption. Only one key needed.
# this is a 16 bytes key, os.urandom(16) can be a good generator.
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

@app.route('/')
def index():
  if 'username' in session:
		username = escape(session['username'])
	  return "You're logged in as %s" % username
	else:
    return "You're not logged in!"

  
@app.route('/login', methods=['GET', 'POST'])
def login():
	if request.method == 'GET':
  	login_form = """
  		<form method="post">
  			<input type="text" name="username" />
  			<input type="submit" value="login!" /> 
  		</form>
  	"""
  	return login_form
  
  if request.method == 'POST'
  	session['username'] = request.form['username']
		return redirect(url_for('index'))

  
@app.route('/logout')
def logout():
  session.pop('username', None)
  return redirect(url_for('index'))
```

In this example, the `/` page indicates wheather the username is set. `/login` and `/logout` page set the remove username in session respectively.



### 8. Files Upload

You should able to understand this through the following demo:

```python
@app.route('/')
def index():
	return "hello, you're in the index page!"

@app.route('/upload', methods=['GET', 'POST'])
def upload():
  if request.method == 'GET':
    form_page = """
   	<form method="post" enctype="multipart/form-data">
    	<input type="file" name="the_file" />
    	<input type="submit" />
    </form>
    """
    return form_page
  
  if request.method == 'POST':
    f = requests.files['the_file']
    f.save('/User/rex/hello.txt')
    return redirect('/')
```

Notices that the `<from>` element should has attribuate `enctype="multipart/form-data"` to make the browser support file transfer, otherwise no files will be transfer to the server.



### 9. Error Handler

You can manually `abort` the page to any kinds of error, and handle any kinds of errors by `errorhandler` decorator.

```python
from flask import abort

@app.route('/notexist')
def notexist():
  abort(404)
  
  
@app.errorhandler(404)
def not_found(error):
  print(error)  # This stores the error info in code-specific class
  							# for 404, it's <class 'werkzeug.exceptions.NotFound'>
  return "NOT FOUND", 404
```




