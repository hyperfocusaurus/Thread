var Thread = require('./build/Release/Thread.node');

console.log('1');
Thread(function (test) {
    var start = Date.now();
    while(Date.now() - start < 50);
    console.log('2');
});
console.log('3');