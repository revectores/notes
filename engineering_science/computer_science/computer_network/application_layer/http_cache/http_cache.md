# HTTP Cache

##### 



##### # Cache Processing

Three steps in cache processing:

1. **Cache existence check**. If the cache does not exist in caching server, the server transmit request/response and store a copy.

2. **Freshness check.** Some HTTP responses contain `Expires` header, which sets a absolute expiration date of the page, or the `Cache-Control: max-age=<seconds>` header, which set a relative expiration time (relative to `Date` that tells the creation time of response) of the page, or both, for backward compatibility. The caching server first checks whether an historical response is not expired for now. If not expired, **cache hits**.

3. **Revalidate**. Even if the cache has expired already, it is still possible that the server has not changed the content of that page for now, hence a revalidation is executed, which is called a **conditional GET**. A `if-modified-since` header is added into the HTTP request header and sent to server, if not, a **304 Not Modified** response without content will be given by the server (with the new freshment information), in this case we get a **revalidate hit** or **slow hit**. Otherwise the response will be the normal **200 OK** with modified contents, this is a **revalidate miss**.

    Specially, a `Cache-control: must-revalidate` header can be set by the client that forces the caching server to revalidate the cache.

