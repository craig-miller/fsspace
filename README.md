# fsspace

Queries a specified filesystem for usage statistics including:
  * Bytes Total
  * Bytes Available
  * Bytes Used
  * Percent Used  

The module uses Unix system libraries and is implemented in native C++ via node-gyp.

## Code Example

	var fsspace   = require('fsspace');

	// Get root filesystem (/) usage
	fsspace.status('/', function(err, bytesTotal, bytesAvail, bytesUsed, pctUsed) {
        console.log("bytesTotal=" + bytesTotal);
        console.log("bytesAvail=" + bytesAvail);
        console.log("bytesUsed=" + bytesUsed);
        console.log("pctUsed=" + pctUsed);
	});

## Motivation

A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.

## Installation

Install fsspace locally:

	$ npm install fsspace

or if you would like to save this as a dependency to your package.json file you can use:
	$ npm install fsspace --save

## API Reference
Use 	`require('fsspace');` to access this module.

The module only has a single method in it's API.
### status(filesystem, callback);
#### filesystem
The filesystem to gather usage data about.
#### callback
`function(err, bytesTotal, bytesAvail, bytesUsed, pctUsed){ // Do something}`

**err**:  Contains an error message on failure.  
**bytesTotal**:  Size of this filesystem in bytes.  
**bytesAvail**:  Available space on this filesystem to a normal user process in bytes.  
**bytesUsed**:   Amount of space on this filesystem that is currently being used in bytes.  
**pctUsed**:     Percent of total space that is currently being used (0-100).

## Tests

In order to run the tests, you need to:
	* clone the repo
	* npm install to install the mocha test dependencies
	* npm test

	$ git clone git@github.com:craig-miller/fsspace.git
	$ cd fsspace
	$ npm install
	$ npm test
	
## Contributors

Please feel free to submit additional features.  In particular it would be great to get support for Windows.

github homepage:  https://github.com/craig-miller/fsspace  
Issue tracker:    https://github.com/craig-miller/fsspace/issues  
IRC:			 		 #spatialminds on freenode  
Twitter:          @spatialminds  

## License

MIT

Copyright (c) 2014 Spatial Minds, LLC

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.