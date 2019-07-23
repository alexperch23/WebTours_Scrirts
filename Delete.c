int i, Random, Size, RandomDelete;

Delete()	
{

	lr_start_transaction("WebTours_Main_03_Delete");
	
	lr_think_time(75);
	
	lr_start_transaction("WebTours_03_01_Itinerary");
	
	web_reg_save_param_ex(
    	"ParamName=FlightNumber", 
    	"LB/IC=<input type\=\"hidden\" name\=\"flightID\" value\=\"",
    	"RB/IC=\"  />",
    	"Ordinal=all",
    	"SaveLen=-1",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=ID", 
    "LB/IC=<input type\=\"hidden\" name\=\".cgifields\" value\=\"",
    "RB/IC=\"  />",
    "Ordinal=all",
    "SaveLen=-1",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);
	
	web_reg_find("Text=No flights have been reserved.","Fail=Found",
	LAST); 
	          
	web_url("Itinerary Button", 
		"URL=http://{Domain}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("WebTours_03_01_Itinerary",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("WebTours_03_02_Delete");
	
	Size = atoi(lr_eval_string("{FlightNumberCount}"));
	
	RandomDelete = rand()%Size + 1;
	
	if (Random >= 10)
		lr_param_sprintf("Request","%d=on&",RandomDelete);
	else
		lr_param_sprintf("Request","");
	
	for(i = 1; i < Size + 1; i++) {
		lr_param_sprintf("Request","%sflightID=%s&", lr_eval_string("{Request}"), lr_paramarr_idx("FlightNumber",i));
	}
	
	lr_output_message("String is %s", lr_eval_string("{Request}"));
	
	for(i = 1; i < Size + 1;i++)
	{
		lr_param_sprintf("Request","%s.cgifields=%s&", lr_eval_string("{Request}"), lr_paramarr_idx("cgifieldsId",i));
	}
	
	if(Random >= 10)
		lr_param_sprintf("Request", lr_eval_string("{Request}removeFlights.x=36&removeFlights.y=4"));
	else
		lr_param_sprintf("Request", lr_eval_string("{Request}removeAllFlights.x=44&removeAllFlights.y=8"));
	
	web_reg_find("Text=itinerary", 
	LAST);
	
	web_custom_request("itinerary.pl_2", 
		"URL=http://{Domain}:{Port}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/itinerary.pl", 
		"Snapshot=9.inf", 
		"Mode=HTML", 
		"Body={Request}",
		LAST);

	lr_end_transaction("WebTours_03_02_Delete",LR_AUTO);
	
	lr_think_time(10);
	
	lr_start_transaction("WebTours_03_03_SignOff");
	
	web_reg_find("Text=Welcome",
	LAST);
	
	web_url("welcome.pl", 
		"URL=http://{Domain}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Domain}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("WebTours_03_03_SignOff",LR_AUTO);
	
	lr_think_time(64);
	
	lr_end_transaction("WebTours_Main_03_Delete", LR_AUTO);
	
	lr_think_time(38);

	return 0;
}