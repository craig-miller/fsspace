// Include libraries
var fsspace   = require('../'),
    should  = require('should'),
    assert  = require('assert');

function asyncTest() {
    fsspace.status('/', function(err, bytesTotal, bytesAvail, bytesUsed, pctUsed) {
        assert(!err);
        assert(bytesTotal > 0);
        assert(bytesAvail > 0);
        assert(bytesUsed > 0);
        assert(pctUsed >= 0);
        assert(pctUsed <= 100);

        console.log("bytesTotal=" + bytesTotal);
        console.log("bytesAvail=" + bytesAvail);
        console.log("bytesUsed=" + bytesUsed);
        console.log("pctUsed=" + pctUsed);

        
    });
    
    setTimeout( function() { asyncTest(); }, 10000);
}

console.log ("Press ctrl-c to exit this test.");
asyncTest();

