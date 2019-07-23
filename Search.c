int PassangerCount, Back_F;
char *RFI;
char *RFB;

Search()
{
	lr_start_transaction("WebTours_Main_01_Search");
	
	srand(time(NULL));
	PassangerCount = rand()%3 + 1;
	Back_F = rand()%3 + 1;
	
	lr_save_int(PassangerCount,"Count_Param");
	lr_save_int(Back_F,"Back_F");
	
	lr_think_time(86);
	
	lr_start_transaction("WebTours_01_01_Url");
	
	web_reg_save_param_ex(
    	"ParamName=UserSess", 
    	"LB/IC=<input type\=\"hidden\" name\=\"userSession\" value\=\"",
    	"RB/IC=\"/>",
    	"Ordinal=1",
    	"SaveLen=-1",
    SEARCH_FILTERS,
    	"Scope=body",
	LAST);
	
	web_reg_find("Text=Welcome",
   	LAST );
	
	web_url("webTours", 
		"URL=http://{Domain}:{Port}/webTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
	LAST);
	
	lr_end_transaction("WebTours_01_01_Url",LR_AUTO);
	
	lr_think_time(78);
	
	lr_start_transaction("WebTours_01_02_Login");
	
	web_reg_find("Text=Welcome, ",
        LAST );
	
	web_submit_data("login.pl", 
		"Action=http://{Domain}:{Port}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=userSession", "Value={UserSess}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=36", ENDITEM, 
		"Name=login.y", "Value=3", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
	LAST);
	
	lr_end_transaction("WebTours_01_02_Login",LR_AUTO);
	
	lr_think_time(46);
	
	lr_start_transaction("WebTours_01_03_Flights");
	
	web_reg_find("Text=Find Flight",
    LAST );
	
	web_url("Search Flights Button", 
		"URL=http://{Domain}:{Port}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
	LAST);
	
	lr_end_transaction("WebTours_01_03_Flights",LR_AUTO);
	
	lr_think_time(42);
	
	lr_start_transaction("WebTours_01_04_Find");
	
	web_reg_save_param_ex(
    	"ParamName=Book_In", 
    	"LB/IC=<input type\=\"radio\" name\=\"outboundFlight\" value\=\"",
    	"RB/IC=\"",
    	"Ordinal=all",
    	"SaveLen=-1",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);
	
	web_reg_find("Text=Flight departing",
    LAST );
	
	if(Back_F == 1) {
		
	web_submit_data("reservations.pl", 
		"Action=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={Departure_City}", ENDITEM, 
		"Name=departDate", "Value={Departure_Date}", ENDITEM, 
		"Name=arrive", "Value={Arrival_City}", ENDITEM, 
		"Name=returnDate", "Value={Arrival_Date}", ENDITEM, 
		"Name=numPassengers", "Value={Count_Param}", ENDITEM,  
		"Name=seatPref", "Value={Seat_Pref}", ENDITEM, 
		"Name=seatType", "Value={Seat_Type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=40", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
	LAST);
	}
	
	else if(Back_F == 2) {
		
	web_reg_save_param_ex(
    	"ParamName=Book_Back", 
    	"LB/IC=<input type\=\"radio\" name\=\"returnFlight\" value\=\"",
     	"RB/IC=\"",
    	"Ordinal=all",
    	"SaveLen=-1",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);
	
	web_submit_data("reservations.pl", 
		"Action=http://{Domain}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
	ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={Departure_City}", ENDITEM, 
		"Name=departDate", "Value={Departure_Date}", ENDITEM, 
		"Name=arrive", "Value={Arrival_City}", ENDITEM, 
		"Name=returnDate", "Value={Arrival_Date}", ENDITEM, 
		"Name=numPassengers", "Value={Count_Param}", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={Seat_Pref}", ENDITEM, 
		"Name=seatType", "Value={Seat_Type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=40", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
	LAST);
	}
	
	lr_end_transaction("WebTours_01_04_Find",LR_AUTO);
	
	lr_end_transaction("WebTours_Main_01_Search", LR_AUTO);
	
	lr_think_time(57);

	return 0;
}