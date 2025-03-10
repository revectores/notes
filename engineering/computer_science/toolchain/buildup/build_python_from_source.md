### Built Python From Source


The `README.rst` file gives the steps to build Python from source:

```{.shell .numberLines startFrom="61"}
./configure
make
make test
sudo make install
```

Specifically, in MacOS (At least for Python 3.9 and MacOS 10.15) you need to specify the location of `openssl` explicitly by

```shell
> ./configure --with-openssl=$SSL_PATH
```

the `SSL_PATH` can be found by 

```sh
> brew --prefix openssl
```

if your `openssl` is installed using Homebrew.

/usr/bin/openssl

