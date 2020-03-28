## Flask Server Configuration Workflow
1. Update yum for centOS and apt-get for ubuntu
This is considered as the best practice, cause the preinstalled software is out-of-date.
```bash
yum -y update
```
In this document we will use centOS-style commands as the example.


2. Get Python3
Normally the python2.7 is preinstalled in the Linux server, you can check this by
```bash
python -v
```
Since the python2 is deprecated with lots of different behaviors, there is no doubt that we need to install the python3 as default interpreter.
```bash
sudo yum install -y https://centos7.iuscommunity.org/ius-release.rpm
sudo yum install -y python36u python36u-libs python36u-devel python36u-pip
python3.6 -v
```
It seems that this rpm source doesn’t support python3.7 still. This is easy to fix in the future.
One of the most important thing to avoid using error version(2.7) is to create alias for bash:
```bash
# ~/.bashrc
alias python='python3.6'
alias python2.7='python'
alias pip='pip3.6'
alias pip2.7='pip'
```
This approach seems not so elegant and easy to cause misunderstandings but it works fine now, we can fix this in the future too (one simpler approach is to create soft-link or whatever it calls).


3. Get flask & gunicorn
```bash
pip install flask  # notice that now the pip is actually pip3.6
pip install gunicorn
```


4. Get wget & nginx
```bash
sudo yum install wget
sudo yum install epel-release
sudo yum install nginx
```


5. A Hello World Program
```python
# /home/flask/run.py
from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return '<h1>Hello World!</h1>'

if __name__ == '__main__':
    app.run()
```
```bash
nohup gunicorn -w 4 -b 0.0.0.0:5000 run:app &
exit
```
Now if everything goes fine you can view this website from the public IP (or domain name)



