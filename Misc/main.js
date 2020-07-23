//Pass a json data as postData
function postUserData () {
	//Grab the variables from the form using the jquery search for their ID
	//and using the built in .val() function to get the contents
	var ticketID = $('#ticketID').val();
	var seatID = $('#seatID').val();
	var ownerID = $('#ownerID').val();

	//Output the values to the console for debugging purposes
	console.log(ticketID);
	console.log(seatID);
	console.log(ownerID);

	//Create a data object that is in the same format as the REST API expected parameters
	theData = {
  	"$class": "org.acme.tickets.Ticket",
 	 "ticketID": ticketID,
 	 "seatID": seatID,
 	 "eventDateTime": " ",
 	 "eventTitle": " ",
	  "venue": " ",
	  "owner": "resource:org.acme.tickets.TicketHolder#" + ownerID
	}

	//Output the data to the console for debugging purposes
	console.log(theData);

	//AJAX function that runs in parallel as the page is loading and posts the JSON
    $.ajax({
    	// the URL for the request
        url: " http://148.100.4.122:3000/api/org.acme.tickets.Ticket",
        // whether this is a POST or GET request
        type: "POST",
        //the type of the data being sent to the REST API
        dataType: "json",
        //the name of the data we will send or get back
        data: theData,
        // If this REST API call executes successfully run this function
        success: function (ticket) {
            var param = $.param(ticket);
            console.log(param);
            $('#ticketDiv').append("<b>Added a Ticket</b>");
        },
        // If this REST API call executes unsuccessfully run this function
        error: function (xhr, status) {
            // code run if request fails; raw request and status
            console.log("Sorry, there was a problem!");
            console.log(status);
            console.log(xhr);
        },
        // Run this function regardless of success or failure
        complete: function (xhr, status) {
        	console.log("The request is complete!");
        }
    });
}

//jQuery shorthand to wait for the webpage to finish loading before running the following script
$( document ).ready(function() {
	//All functions are now running based on a click of the #clickhere object
	$('#clickhere').click(function() {
		console.log('Button Clicked');
		postUserData();
	});
});
