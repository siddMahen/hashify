# hashify

Native v8 object hashes made available.

## Installation

To install, do:

    $ npm install hashify

## Usage

To get the hash of the object simply do:

    var hashify = require("hashify");

    console.log(hashify({ a : "b" }));
    // 441581404

The returned hash will never to equal to 0, however
it is is not guaranteed to be unique.
