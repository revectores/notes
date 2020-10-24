# Same Origin Policy

##### # Definition

Two URLs have the **same origin** if the protocol, port, and host are the same for both.

Specially, scripts executed from pages with an `about:blank` or `javascript:` URL inherit the origin of the document containing that URL, since these types of URLs do not contain information about the origin server.

The XMLHttpRequest request, known as AJAX, can only get the contents from the same origin. While some HTML labels with `src` attribute like `<script>, <img>, <iframe>, <link> ` can load the resources interdomain.





