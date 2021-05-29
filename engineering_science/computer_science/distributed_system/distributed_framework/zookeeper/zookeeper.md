# Zookeeper

### 1. The Zookeeper Service

##### # znode

ZooKeeper provides to its clients the abstraction of a set of data nodes(**znodes**), organized according to a hierarchical name space. All znodes store data, and all znodes, except for ephemeral znodes, can have childrens.

There are two types of znodes that a client can create:

- **Regular**: Must be deleted explicitly.
- **Ephemeral**: Can either be deleted explicitly or be removed automatically when the session that creates them terminates (deliberately or due to a failure).

Additionally, when creating a new znode, a client can set a **sequential flag**. Nodes created with the sequential flag set have the value of a monotonically increasing counter appended to its name.

ZooKeeper implements **watches** (similar to semaphore for local OS, as will shown from the following description) to allow clients to receive timely notifications of changes without requiring polling. Watches are one-time triggers, and do not provide the change.



##### # Client API

(A subset of) Client APIs presented in zookeeper paper:

`create(path, data, flags)`: Creates a zonde with path name `path`, stores `data[]` in it, and returns the name of the new znode. `flags` enables a client to select the type of znode: **regular**, **ephemeral**, and set the **sequential flag**.

`delete(path, version)`: Deletes the znode `path` if that znode is at the expected version.

`exists(path, watch)`: Returns true if the znode with path name `path` exists, and returns false otherwise. The `watch` flag enables a client to set a watch on the znode.

`getData(path, watch)`: Returns the data and meta-data, such as version information, associated with the znode. The `watch` flag works in the same way as it does for `exists()`, expect that ZooKeeper does not set the watch if the znode does not exist.

`setData(path, data, version)`: Writes `data[]` to znode `path` if the version number is the current version of the znode.

`getChildren(path, watch)`: Returns the set of names of the children of a znode.

`sync(path)`: Waits for all updates pending at the start of the operation to propagate to the server that the client is is connected to. The path is currently ignored.

All methods have both a synchronous API and asynchronous API.



##### # ZooKeeper Garantees

ZooKeeper has two basic ordering guarantees:

- **Linearizable writes**: all requests that update the state of ZooKeeper are serializable and respect precedence.
- **FIFO client order**: all requests from a given client are executed in the order that they were sent by the client.

