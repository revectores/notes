# Dockerfile Format

A `Dockefile` is a text document that contains all the commands a user could call on the command line to assemble an image. Docker can build images automatically by reading the instructions from a `Dockerfile` using `docker build`.

The `docker build` command builds an image from a `Dockerfile` and a context. The build's context is the set of files at a specified location `PATH` (a directory on your local filesystem) or `URL` (a git repo).

