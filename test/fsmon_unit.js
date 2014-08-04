// Include libraries
var fsspace   = require('../'),
    should  = require('should'),
    assert  = require('assert');

describe('fsspace tests', function (){ 
    describe('status() positive test', function() {
        it('Should have positive values and no err.', function() {
            fsspace.status('/', function(err, bytesTotal, bytesAvail, bytesUsed, pctUsed) {
                assert(!err);
                assert(bytesTotal > 0);
                assert(bytesAvail > 0);
                assert(bytesUsed > 0);
                assert(pctUsed >= 0);
                assert(pctUsed <= 100);
            });
        }); 
    });
});

