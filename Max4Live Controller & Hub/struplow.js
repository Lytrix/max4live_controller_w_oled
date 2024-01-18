
/*
	simple javascript string case conversion object
*/

// set up inlets/outlets/assist strings
setinletassist(0,"toupper/tolower");
setoutletassist(0,"case converted string (symbol)");

function toupper()
{
	var i;
	var a = new Array();
	
	// the arguments object is special kind of object rather than a simple array, 
	// and will not behave like an array when passed as an argument to outlet()
	for (i=0;i<toupper.arguments.length;i++) 
	{
		a[i] = toupper.arguments[i].toString().toUpperCase();  
	}	
	outlet(0,a);				
}


function tolower()
{
	var i;
	var a = new Array();

	// the arguments object is special kind of object rather than a simple array, 
	// and will not behave like an array when passed as an argument to outlet()
	for (i=0;i<tolower.arguments.length;i++) 
	{
		a[i] = tolower.arguments[i].toString().toLowerCase();  
	}	
	outlet(0,a);				
}

