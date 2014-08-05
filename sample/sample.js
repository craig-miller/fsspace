// Include libraries
var fsspace   = require('fsspace');

fsspace.status('/', function(err, bytesTotal, bytesAvail, bytesUsed, pctUsed) {
        console.log("bytesTotal=" + bytesTotal);
        console.log("bytesAvail=" + bytesAvail);
        console.log("bytesUsed=" + bytesUsed);
        console.log("pctUsed=" + pctUsed);
});
