Booking()
{

	lr_start_transaction("WebTours_Main_02_Booking");
	
	lr_think_time(37);

	lr_start_transaction("WebTours_02_01_Fligh");
	
	web_reg_find("Text=Street Address",
    LAST );
	
	RFI = lr_paramarr_random("Book_In");
	
	lr_param_sprintf("FlightIn",lr_eval_string(RFI));
	
	if(Back_F == 1) {	
		
	web_submit_data("reservations.pl_2", 
		"Action=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=outboundFlight", "Value={FlightIn}", ENDITEM, 
		"Name=numPassengers", "Value={PassangerCount}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={Seat_Type}", ENDITEM, 
		"Name=seatPref", "Value={Seat_Pref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=17", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
	LAST);
	}
	
	else if(Back_F ==2) {
		
	RFB = lr_paramarr_random("Book_Back");
		
	lr_param_sprintf("FlightBack",lr_eval_string(RFB));
		
	web_submit_data("reservations.pl_2", 
		"Action=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=outboundFlight", "Value={FlightIn}", ENDITEM, 
		"Name=returnFlight", "Value={FlightBack}", ENDITEM, 
		"Name=numPassengers", "Value={PassangerCount}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={Seat_Type}", ENDITEM, 
		"Name=seatPref", "Value={Seat_Pref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=17", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
	LAST);
	}
	
	lr_end_transaction("WebTours_02_01_Fligh",LR_AUTO);

	lr_think_time(46);
	
	lr_start_transaction("WebTours_02_02_PaymentDetails");

	web_reg_find("Text=Credit Account",
    LAST );
        
	if(Back_F !=2)
		
	lr_param_sprintf("ReturnFlight","");
	
	switch(PassangerCount) {
			
	case 1:
			
	web_submit_data("reservations.pl_3", 
		"Action=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=firstName", "Value={Name}", ENDITEM, 
		"Name=lastName", "Value={Second_Name}", ENDITEM, 
		"Name=address1", "Value={Street}", ENDITEM, 
		"Name=address2", "Value={Departure_City}", ENDITEM, 
		"Name=pass1", "Value={Name} {Second_Name}", ENDITEM, 
		"Name=creditCard", "Value={Credit_Card}", ENDITEM, 
		"Name=expDate", "Value={Exp_Data}", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={Seat_Type}", ENDITEM, 
		"Name=seatPref", "Value={Seat_Pref}", ENDITEM, 
		"Name=outboundFlight", "Value={FlightIn}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={FlightBack}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=40", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
	LAST);	
			
	break;
	
	case 2:
		web_submit_data("reservations.pl_3", 
		"Action=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=firstName", "Value={Name}", ENDITEM, 
		"Name=lastName", "Value={Second_Name}", ENDITEM, 
		"Name=address1", "Value={Street}", ENDITEM, 
		"Name=address2", "Value={Departure_City}", ENDITEM, 
		"Name=pass1", "Value={Name} {Second_Name}", ENDITEM, 
		"Name=pass2", "Value={Second_Passenger}", ENDITEM,
		"Name=creditCard", "Value={Credit_Card}", ENDITEM, 
		"Name=expDate", "Value={Exp_Data}", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={Seat_Type}", ENDITEM, 
		"Name=seatPref", "Value={Seat_Pref}", ENDITEM, 
		"Name=outboundFlight", "Value={FlightIn}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={FlightBack}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=40", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
	LAST);
	
	break;
	}

	lr_end_transaction("WebTours_02_02_PaymentDetails",LR_AUTO);

	lr_think_time(34);

	lr_start_transaction("WebTours_02_03_SingOff");
	
	web_reg_find("Text=Welcome",
	LAST);
	
	web_url("welcome.pl", 
		"URL=http://{Domain}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
	LAST);

	lr_end_transaction("WebTours_02_03_SingOff",LR_AUTO);
	
	lr_think_time(67);
	
	lr_end_transaction("WebTours_Main_02_Booking", LR_AUTO);
	
	lr_think_time(78);
	
	return 0;
}
