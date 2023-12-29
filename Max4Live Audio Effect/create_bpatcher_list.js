
var setBpatchers = new Array();
var createdBpatchers = new Array();
var myval=0;

var x_pos = 0;
var y_pos = 0;

var created = 0;

if (jsarguments.length>1)
	myval = jsarguments[1];

function bang()
{
	outlet(0,"myvalue","is",myval);
}

function msg_int(v)
{
	post("received int " + v + "\n");
	myval = v;
	bang();
}

function msg_float(v)
{
	post("received float " + v + "\n");
	myval = v;
	bang();
}

function list()
{
	var a = arrayfromargs(arguments);
	post("received list " + a + "\n");
	myval = a;
	bang();
}

function anything()
{
	remove_bp();  
	var a = arrayfromargs(messagename, arguments);
	//post("received message " + a + "\n");
	myval = a;
	
	myval.forEach(myFunction);			
	bang();
}


function myFunction(item, index, arr) {
  post("One item: " + index +" "+ item + "\n");
  y_pos = index * 25;

  setBpatchers[0] = x_pos;
  setBpatchers[1] = y_pos;
  setBpatchers[2] = "bpatcher";
  setBpatchers[3] = "Parameter_Select.maxpat";
			
  createdBpatchers[index] = patcher.newdefault(setBpatchers);
}


function remove_bp(){
	y_pos = 0;
	for (i=0;i<myval.length;i++){
		patcher.remove(createdBpatchers[i]);
	}
}