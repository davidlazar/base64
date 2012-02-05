# About

*base64* is a fork of [libb64](http://libb64.sourceforge.net/) with the following notable differences:

* The *base64* API more closely resembles the API of a hash function (`init`, `update`, `final`).
* Currently, *base64* only provides an encoding routine.
* The output of the *base64* encoding routine does not include newlines.
* Variables have been renamed for clarity.
* This code is accessible over git/hg.

# Usage

To build the code:

    $ make

Note, using `CC=clang` produces faster code on my machine. To test the code:

    $ echo -n 'foobar' | ./b64enc -
    Zm9vYmFy

# License

Public domain. Do whatever you want with the code. The code comes without any warranty.

# Contributing

This project is available on [GitHub](https://github.com/davidlazar/base64) and [Bitbucket](https://bitbucket.org/davidlazar/base64/). You may contribute changes using either.

Please report bugs and feature requests using the [GitHub issue tracker](https://github.com/davidlazar/base64/issues).
