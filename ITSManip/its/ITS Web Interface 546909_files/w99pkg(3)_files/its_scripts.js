/* ************************************************************************
   Program : its_scripts.js
   Version : 
   Changed : 31-MAR-2005 Ollie T119686 Add errReportBack logic
           : 07-JUL-2005 Ollie T121995 Add forceUpper logic    
           : 13-Sep-2005 Els t117575 No change - entry for bookpgm
           : 01-Feb-2006 Asit F128105 in isnumber use parseFloat iso parseInt
           : 14-NOV-2006 MUK T135979 added function run_LOV
           : 13-Feb-2007 VD  T124686 Add textLimit
           :                         Add imposeMaxLength
           : 19-Feb-2007 Els f139903 merged V13 and Int1 its_scripts.js as 
           :             changes from 31-Mar-2005 to 1-Feb-2006 was not on Int1
           : 06-Jun-2007 Adele T142258 Create a secure generic global LOV 
           : running mechanism - run_lov_secure.  
           : 21-Aug-2007 Jan t140791 Also check for 'P' when collecting data
           :                         for RC
           : 18-Feb-2008 Adele 148155(147116) Added X_SEARCH_BY_CODE parameter 
           : to Javascript function run_lov_secure. 
           : 28-Feb-2008 Sonja T147569 Comment out ITSinit (right click)
           : 05-Mar-2008 DG T148854 Added focus to LOV window
           : 24-Feb-2009 Dinong T155997 Add run_lov_bind
           : 30-Mar-2009 Dinong T156750 Add LOV headings
           : 18-May-2009 Dinong T156757 Add run_lov_bind_jsp
X0_VERSION : v01.0.0.6
   ************************************************************************
*/

<!-- Hide from old browsers

// #######
// Script: Setup Datestamp for printing in Header of all pages
function prt_header_datestamp () {
 days = new Array("Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday");
 months = new Array("January","February","March","April","May","June","July","August","September","October","November","December");
 var today = new Date();
 todayYear = today.getYear();
 todayMonth = months[today.getMonth()];
 todayDay = days[today.getDay()];
 todayDate = today.getDate();
 // Add to end of day number
 if (todayDate == 1 || todayDate == 21 || todayDate == 31) {
 todayDate += "st";
 }
 else {
 if (todayDate == 2 || todayDate == 22) {
 todayDate += "nd";
 }
 else {
 if (todayDate == 3 || todayDate == 23) {
 todayDate += "rd";
 }
 else {
 todayDate += "th";
 }
 }
 }
 // Define print format and write to screen.
 var dsString = todayDay + ", " + todayDate + " " + todayMonth + " " + 
                ((today.getFullYear() < 100) ? "19" : "") + today.getFullYear();
 document.write(dsString);
return(' ');
} // end prt_header_datestamp

// #######
// Script: Mouse over for items
  var x_oldstyle;
  function goOver(ctl)
  {
    // Set the offset as defined for this specific row. To be used for right-click logic
    ITS_Offset = ctl.getAttribute("its_offset");

    if (ctl.className != "rowover") 
       {
       x_oldstyle = ctl.className;
       ctl.className="rowover";
       }
  }
  function goOut(ctl) 
  {
    // Reset the offset back to "Page-level". To be used for right-click logic
    ITS_Offset = "0";
    ctl.className=x_oldstyle;
  }

// #######
// Script: Force text within the field to Uppercase
// Run as: <input .... onChange="forceUpper(this);" ...>
  function forceUpper(ctl)
  {
  ctl.value = ctl.value.toUpperCase();
  }

// #######
// Script: Check if entered value is a number
  function isnumber(ctl)
  {
    if (parseFloat(ctl) != ctl)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

function run_lov_secure(formName,codeName,descName,code,descr,fromClause,whereClause,lov_title,code_title,descr_title,showCode,theFilter,chkSum,returnRow) {
// T148854 Add returnRow parameter to function run_lov_secure and remove run_lov_multi from script file.
 var the_pathname = location.pathname;
 var i = the_pathname.indexOf ("/:");
 var j = the_pathname.indexOf ("/", ++i);

 if (i != -1) { // Syntactically incorrect url so it needs to be corrected
  the_pathname = the_pathname.substring (j, the_pathname.length);
 }; // (i != -1)
 if (returnRow == undefined) { returnRow = "-1"; }

 frmLOV = open("web.w01pkg.w01_lov_proc_sec" +
  "?X_FILTER=" + escape(theFilter) +
  "&X_CODE=" + escape(code) +
  "&X_DESCR=" + escape(descr) +
  "&X_FROM="+ escape(fromClause) +
  "&X_WHERE="+ escape(whereClause) +
  "&X_CALLER_URL=" + escape(location.protocol + "//" +
                            location.host + location.pathname +
                            location.search)+
  "&X_LOV_TITLE=" + escape(lov_title) +
  "&X_CODE_TITLE=" + escape(code_title) +
  "&X_DESCR_TITLE=" + escape(descr_title) +
  "&X_SHOW_CODE=" + escape(showCode) +
  "&X_FORM_ITEM_NAME=" + escape(formName) +
  "&X_CODE_ITEM_NAME=" + escape(codeName) +
  "&X_DESC_ITEM_NAME=" + escape(descName) +
  "&X_SEARCH_BY_CODE=" + escape(showCode) +   
  "&X_CHK=" + escape(chkSum) +
  "&X_RETURN_ROW="+ escape(returnRow),
  "winLOV", "scrollbars=yes,resizable=yes,width=450,height=400");
  window.frmLOV.focus();

 if (frmLOV.opener == null) { frmLOV.opener = self; }
} // end of function run_lov_secure

// #######
// Script: 
//-->


<!--

//Disable right mouse click Script
//By Maximus (maximus@nsimail.com) w/ mods by DynamicDrive
//For full source code, visit http://www.dynamicdrive.com

var message="Function Disabled!";

///////////////////////////////////
function clickIE4(){
return true;
if (event.button==2){
alert(message);
return false;
}
}

///////////////////////////////////
// function JSSumdet_Showme toggles the data between Summary and Detail layout
function JSSumdet_Showme(ctl)
{
  if (document.getElementById) // Internet Explorer
  {
    if (document.getElementById("xd"+ctl).style.display=="none")
    {
      document.getElementById("xd"+ctl).style.display="block";
      if (document.getElementById("xs"+ctl))
        document.getElementById("xs"+ctl).style.display="none";
    }
    else
    {
      document.getElementById("xd"+ctl).style.display="none";
      document.getElementById("xs"+ctl).style.display="block";
    }
  }
  else
  {
    document.all.xs1.style.display="block";
    document.all.xd1.style.display="block";
  }
}

///////////////////////////////////
// function JSMark_This gives user option to open or close all records with one click
   var x_sumrecs = 0;
   function JSMark_This(fldInd) {
   var i=1;
   while (i<=c_sumrecs)
     {
     if (fldInd.value=="Open All Records")
        {
        document.getElementById("xd"+i).style.display="block";
        document.getElementById("xs"+i).style.display="none";
        }
     else
        {
        document.getElementById("xd"+i).style.display="none";
        document.getElementById("xs"+i).style.display="block";
        }
   
     i++;
     }
   
   if (fldInd.value=="Open All Records")
      {
      fldInd.value="Close All Records";
      }
   else
      {
      fldInd.value="Open All Records";
      }
   }

///////////////////////////////////
// function JSMark_All Opens all records 
   function JSMark_All() {
   var i=1;
   while (i<=c_sumrecs)
   {
     document.getElementById("xd"+i).style.display="block";
     document.getElementById("xs"+i).style.display="none";
     i++;
   }
   
   }

<!--
////////////////////////////////////////////////////////////////////////////////////////////
//// This function will call any process on the server without actually refreshing the page
//// Please Note that this only works in IE5.5+ and Netscape6+
//// DBProcedure  - Mandatory, This is the Procedure to be called. Must return JavaScript.
////              -            This procedure must ALWAYS contain parameter for x_stmp.
////              -            This timestamp will contain a new value every time the procedure is 
////              -            called and ensures that no caching could be done.
//// DBParameters - Optional , Please start with & as first Parameter will be x_stmp
//// DBTagName    - Optional , Use different values if this function call should not overwrite data
////              -            from another call to the same function. 
////              -            By default this should be left out
////////////////////////////////////////////////////////////////////////////////////////////
function callDynBGproc(DBProcedure,DBParameters,DBTagName) {
	var dynamicScriptAreaTagName="dynScriptArea";
	var d = new Date();   // use the Date field to create a datestamp (to enforce unique URL)

	// Use the given tag name iso the default (if available)
	if (DBTagName && DBTagName != "")
		dynamicScriptAreaTagName=DBTagName;

	// first Ensure that this node does Not Exist. If it does, remove it.
	window.status='Clearing Previous Values';
	xx = document.getElementById(dynamicScriptAreaTagName);
	if (xx != null) {
		xx.parentNode.removeChild(document.getElementById(dynamicScriptAreaTagName));
	}

	// Now create a new SCRIPT Node and point the source to a procedure in the DB
	window.status='Working';
	xscript=document.createElement('script');
	xscript.setAttribute('language','Javascript');
	xscript.setAttribute('type','text/javascript');
	xscript.setAttribute('id',dynamicScriptAreaTagName);
	//alert(DBProcedure+'?x_stmp='+escape(d.getTime())+DBParameters);
	xscript.setAttribute('src',DBProcedure+'?x_stmp='+escape(d.getTime())+DBParameters);
	document.getElementsByTagName('head').item(0).appendChild(xscript);

	window.status='Done';
	return true
}

// -->
// Setup the reportback to *frm of any errors found in the *proc procedures
function errReportBack(err_source,err_string) {
var ErrorScriptAreaTagName="ErrScriptArea";
var err_text="";
if (err_source.length != 0)
   {
   err_text=err_text+err_source;
   }
if (err_string.length != 0)
   {
   err_text=err_text+
            'parent.F3.document.getElementById("ErrorDiv").innerHTML="'+err_string+'<br />&nbsp;"; '+
            'parent.F3.document.getElementById("ErrorDiv").style.display="block"; ';
   }

// Now add logic to ensure error only get reported once and is then removed
err_text=err_text+
         'xx = parent.F1.document.getElementById("'+ErrorScriptAreaTagName+'"); '+
	 'xx.parentNode.removeChild(xx);';


// first Ensure that this node does Not Exist.
xx = parent.F1.document.getElementById(ErrorScriptAreaTagName);
if (xx != null) {
	xx.parentNode.removeChild(parent.F1.document.getElementById(ErrorScriptAreaTagName));
}

// Now create a new ERROR SCRIPT Node and Populate with specified Detail
xscript=parent.F1.document.createElement('script');
xscript.setAttribute('language','Javascript');
xscript.setAttribute('type','text/javascript');
xscript.setAttribute('id',ErrorScriptAreaTagName);
//alert(err_text);
// Use the following line to populate for Internet Explorer
xscript.setAttribute('text','function chk_for_errors() {'+err_text+'}');
parent.F1.document.getElementsByTagName('head').item(0).appendChild(xscript);
// Use the following line to populate the DOM (Throw away errors generated by Internet Explorer)
try{parent.F1.document.getElementById(ErrorScriptAreaTagName).innerHTML='function chk_for_errors() {'+err_text+'}';}catch(e){void(0)}
//alert(parent.F1.document.getElementById(ErrorScriptAreaTagName).innerHTML);
window.status='Done';
}


<!--

/*
//Disable right mouse click Script
//By Maximus (maximus@nsimail.com) w/ mods by DynamicDrive
//For full source code, visit http://www.dynamicdrive.com
*/

var message="Function Disabled!";

///////////////////////////////////
/*
function clickIE4(){
if (event.button==2){
alert(message);
return false;
}
}

function clickNS4(e){
if (document.layers||document.getElementById&&!document.all){
if (e.which==2||e.which==3){
alert(message);
return false;
}
}
}

if (document.layers){
document.captureEvents(Event.MOUSEDOWN);
document.onmousedown=clickNS4;
}
else if (document.all&&!document.getElementById){
document.onmousedown=clickIE4;
}

document.oncontextmenu=new Function("alert(message);return false")
*/
// --> 

//////////////////////////////
function textLimit(field, maxlen) 
{
  if (field.value.length > maxlen + 1)
  alert('Your input has been truncated! Only '+maxlen+' characters are allowed.');
  if (field.value.length > maxlen)
    field.value = field.value.substring(0, maxlen);
}

//////////////////////////////
function imposeMaxLength(Object, MaxLen)
{
  if (eval(Object.value.length) >= eval(MaxLen))
  {
    Object.value = Object.value.substring(0, MaxLen - 1);
  }
}


//////////////////////////////////////////////////////////////////////////
// Mark all table Rows for use with generic Right-click logic
//////////////////////////////////////////////////////////////////////////
var ITS_Offset = 0; // Set offset level to PAGE. Anything above zero will define row level
function setITSOffsetDefinition(){
var v_tr = document.getElementsByTagName("tr");
var v_offset_cntr = 0;
for (var i = 0; i < v_tr.length ; i++)
{
// var v_class = v_tr[i].getAttribute("class"); // This does not seem to work in IE...Try the following:
var v_class = "UNKNOWN";
var v_attr =v_tr[i].attributes;
for (var j = 0; j < v_attr.length ; j++) {
     //alert (v_attr[j].name + "=" + v_attr[j].value);
     if (v_attr[j].name == "class") v_class = v_attr[j].value;
    }
   // alert(v_class);
   if (v_class == "rldata" || v_class == "mrdatadisp" || v_class == "rowover")
      { v_tr[i].setAttribute("its_offset",++v_offset_cntr) } else
      { v_tr[i].setAttribute("its_offset","0") }
   //alert("Class of element " + i + " is : " + v_tr[i].getAttribute("class") + "\n");
}

//
// Testing to see if Attribute is set.
//
//var v_tr = document.getElementsByTagName("tr");
//for (var i = 0; i < v_tr.length ; i++)
//{
//   alert("Class of Row " + v_tr[i].getAttribute("its_offset") + " is : " + v_tr[i].getAttribute("class") + "\n");
//}
}




//////////////////////////////////////////////////////////////////////////////
// Use this function to load an extra javascript file                       //
// x_jsFile = The relative file name that must be uploaded/included         //
//////////////////////////////////////////////////////////////////////////////
function itsUploadJSfile(x_jsFile) {
var html_doc = document.getElementsByTagName('head').item(0);
var vjs = document.createElement('script');
vjs.setAttribute('language', 'javascript');
vjs.setAttribute('type', 'text/javascript');
vjs.setAttribute('src', x_jsFile);
html_doc.appendChild(vjs);
return false;
}

//////////////////////////////////////////////////////////////////////////////
// Use this function to load an extra Stylesheet files                      //
// x_cssFile = The relative file name that must be uploaded/included        //
//////////////////////////////////////////////////////////////////////////////
function itsUploadCSSfile(x_cssFile) {
var html_doc = document.getElementsByTagName('head').item(0);
var vcss = document.createElement('link');
vcss.setAttribute('rel', 'stylesheet');
vcss.setAttribute('type', 'text/css');
vcss.setAttribute('href', x_cssFile);
html_doc.appendChild(vcss);
return false;
}

function viewSource() {
alert('You Pressed View Source');
}
/*
isMozilla = (document.all) ? 0 : 1;
if (isMozilla)
{
d_loc="view-source:" + document.location.href;
d=window.open(d_loc);
}
else
{
d=window.open();
d.document.open('text/plain').write(document.documentElement.outerHTML);
}
}
*/
//////////////////////////////////////////////////////////////////////////////
// Use this function to get a specified value from the html page.           //
// It works either per FORM or per TABLE Column number                      //
// if x_formsOrTD = 'F' then x_ind1=>The Form name,                         //
//                           x_ind2=>The Field Name                         //
//                           x_offset=>The offset within the form           //
//                                     Normally this is row-1 (forms base-0)//
//                                     In Multi-row forms: row-3 (2-Dummies)//
//                                     For non-repeat fields: 0 (i.e year)  //
// if x_formsOrTD = 'T' then x_ind1=>The n'th <td> column (-1 because base0)//
//                           x_ind2=>The n'th textnode within above <td>    //
//                           x_offset=>The specified Row (nothing strange)  //
// if x_formsOrTD = 'P' then x_ind1=> is a parameter name the return value  //
//                                    is the value of the parameter         //
//////////////////////////////////////////////////////////////////////////////
function getRCvalue(x_formsOrTD, x_ind1, x_ind2, x_offset) 
{
 // document.write('FormsorTD:'+x_formsOrTD+' 1:'+x_ind1+' 2:'+x_ind2+' Offset'+ x_offset);
if (x_formsOrTD == 'T') 
   { //x_ind1=>The n'th column/TD, x_ind2=>The n'th textnode
    if (ITS_Offset == "0") {return "";} // Right Click wasnt done inside a legal area
      var v_tr = document.getElementsByTagName("tr");
      for (var i = 0; i < v_tr.length ; i++)
      {
      if (v_tr[i].getAttribute("its_offset") == ITS_Offset) // Get to the right row
         {
         var v_td = v_tr[i].getElementsByTagName("td");
         if (v_td[x_ind1 -1].childNodes[x_ind2].nodeType == "3") // If this is a textNode: return it
            return v_td[x_ind1 -1].childNodes[x_ind2].nodeValue;
         else // else: Assume it is an element (like a tag "<a href...></a>" and return its first child node
            return v_td[x_ind1 -1].childNodes[x_ind2].childNodes[0].nodeValue;
         }
      }
   }// if (x_formsOrTD == 'T')
else 
   {
   if (x_formsOrTD == 'P') 
      { //Get value from URL x_ind2 = parameter
      var UrlPars = new Array()
      UrlPars = location.search.split("?")[1].split("&")
      // document.write(UrlPars[1])
      for (x in UrlPars)
         { ParVal=UrlPars[x]
         var ValPair=ParVal.split('=')
         if (ValPair[0]==x_ind2)
            {
            return ValPair[1]
            }
         }
      return " ";
      }
   else
      {    // if (x_formsOrTD == 'F')
      if (x_formsOrTD == 'F') {
      if (x_offset == '') // Sometimes no offset is needed
         { 
         // Checkbox Works Different. is IT
         if (eval('document.'+x_ind1+'.'+x_ind2+'.type') == "checkbox")
            {
            if (eval('document.'+x_ind1+'.'+x_ind2+'.checked'))
               { return eval('document.'+x_ind1+'.'+x_ind2+'.value'); }
            else
               { return ""; }
         }

         // Radio Buttons are even Worse !@#$%^!@#$%^
         if (eval('document.'+x_ind1+'.'+x_ind2+'.type') == "undefined") 
            {
            if (eval('document.'+x_ind1+'.'+x_ind2+'[0].type') == "radio")
               {
               v_workingFld = eval('document.'+x_ind1+'.'+x_ind2);
               for (ci=0; ci<v_workingFld.length; ci++) 
                  { if (v_workingFld[ci].checked) 
                        { return v_workingFld[ci].value;}
                  }
               return "";
               }
            }
            return eval('document.'+x_ind1+'.'+x_ind2+'.value;');
         }
      else
         { 
         // Checkbox Works Different !@#$%^
         if (eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+'].type') == "checkbox")
            {
            if (eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+'].checked'))
               { return eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+'].value'); } 
            else 
               { return ""; }
            }
         // Radio Buttons are even Worse !@#$%^!@#$%^
         if (eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+'].type') == "undefined")
            {
            if (eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+'][0].type') == "radio")
               {
               v_workingFld = eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+']');
               for (ci=0; ci<v_workingFld.length; ci++) 
                     { if (v_workingFld[ci].checked) { return v_workingFld[ci].value;}}
               return "";
               }
            }
         // TODO: Add code to get selectedindex....value detail
         return eval('document.'+x_ind1+'.'+x_ind2+'['+x_offset+'].value;');
         }
      }
   else
      {
      return "";
      }
   }
}
}
///////////////////////////////////////////////////////////////////////////
// Use AJAX to request the Right-Click-Menu items and instructions.      //
// NOTE: The "Request" only forwards the query.                          //
//     : Look in the "Response" part for the actual code                 //
///////////////////////////////////////////////////////////////////////////
function  ItsRCMenu_AjaxRequest() {
  // Get the Procedure name
  var v_urlArr = location.href.toLowerCase().split("?"); // First remove any input parameters
      v_urlArr = v_urlArr[0].split(".");                 // split on the dots
  var v_urlLength = v_urlArr.length;
  var v_urlProcedure = v_urlArr[v_urlLength-1];          // Take the stuff behind the last dot
  // Get the Package name
  v_urlArr = v_urlArr[v_urlLength-2].split("/");
  v_urlLength = v_urlArr.length;
  var v_urlPackage = v_urlArr[v_urlLength-1];           // Take the stuff before the last dot
  // Get the DAD
 //alert(location.href.toLowerCase().split("/pls/")[1].split("/")[0]);
 var v_dad = '';
 if (location.href.toLowerCase().split("/pls/").length > 1)
     { v_dad = '/pls/'+location.href.toLowerCase().split("/pls/")[1].split("/")[0]; }
 else
     { v_dad = '/'    +location.href.toLowerCase().split(":")[2].split("/")[1]; }
 
  // Setup the AJAX request
  var v_url  = v_dad+'/wr02pkg.wr02_getRCmenu';
      v_url += '?x_pkg='+encodeURIComponent(v_urlPackage)+'&x_proc='+encodeURIComponent(v_urlProcedure)+'&x_offset='+encodeURIComponent(ITS_Offset);   
      // v_url = v_dad+'/wr02pkg.wr02_getRCmenu?x_pkg=w99pkg&x_proc=mi_main_menu&x_offset=0';
      // TODO: Maybe add a timestamp to the above v_url
  // Do the AJAX Call
  var xmlHttp=GetXmlHttpObject();
  SetXmlHttphandler(function() { ItsRCMenu_AjaxResponse(xmlHttp); },xmlHttp);
  xmlHttp.open("GET", v_url , false);
  xmlHttp.send();
}
//////////////////////////////////////////////////////////////////////////////
// Use AJAX response to format the Right-Click-Menu items and instructions. //
// Note: Parameters for addMenuItem is as follows:                          //
//       1) Description/name of menu entry to be displayed                  //
//       2) Name of the Submenu linked to this option                       //
//       3) Instruction to be performed when user chooses this option       //
//   NOTE: An entry can either be a submenu link or an instruction not both //
//////////////////////////////////////////////////////////////////////////////
function ItsRCMenu_AjaxResponse(xmlHttp) 
{ 
  if (xmlHttp != null && (xmlHttp.readyState==4 || xmlHttp.readyState=="complete"))
  {
    var v_response = xmlHttp.responseXML.documentElement;
    if (v_response != null) {
    if (v_response.getElementsByTagName('MENU_ROW')[0] == null)
    {
      var error_message="";
      if (v_response.getElementsByTagName('error_description')[0] == null) 
         { error_message=""; }
      else          
         { error_message = v_response.getElementsByTagName('error_description')[0].firstChild.data; }
      var java_error_message="";
      if (v_response.getElementsByTagName('java_error_description')[0] != null)
       {
       java_error_message = v_response.getElementsByTagName('java_error_description')[0].firstChild.data;
       }
      itsRCmenu = new jsDOMenu(500); // The parameter (500) is the display width of the popup
      itsRCmenu.addMenuItem(new menuItem(error_message,"",""));
      if (java_error_message != "") itsRCmenu.addMenuItem(new menuItem(java_error_message,"",""));
      itsRCmenu.addMenuItem(new menuItem("-",""," "));
      itsRCmenu.addMenuItem(new menuItem("Response Status Code="+xmlHttp.status, "", ""));
      itsRCmenu.addMenuItem(new menuItem("Response Status Text="+xmlHttp.statusText, "", ""));
      itsRCmenu.addMenuItem(new menuItem("Response Full Text="+xmlHttp.responseText, "", ""));
      itsRCmenu.addMenuItem(new menuItem("-",""," "));
      itsRCmenu.addMenuItem(new menuItem("View Source", "", "javascript:viewSource();"));
    }
    else
    {
    var v_menuRows = v_response.getElementsByTagName('MENU_ROW');
    // First build the individual menu structures
    for (v_c01 = 0; v_c01 < v_menuRows.length; v_c01++) 
        {
        var v_str  = '';
            v_str += v_menuRows[v_c01].getElementsByTagName('name')[0].firstChild.data;
            v_str += ' = new jsDOMenu(';
            v_str += v_menuRows[v_c01].getElementsByTagName('length')[0].firstChild.data;
            v_str += ');';
            eval(v_str);
            
        // Add the individual items in this menu
        var v_menuItems = v_menuRows[v_c01].getElementsByTagName('MENU_ITEMS');
        for (v_c02 = 0; v_c02 < v_menuItems.length; v_c02++)
            {
            // alert(v_menuItems[v_c02].getElementsByTagName('description')[0].firstChild.data);
            var v_str  = '';
            v_str += v_menuRows[v_c01].getElementsByTagName('name')[0].firstChild.data;
            v_str += '.addMenuItem(new menuItem("';
            v_str += v_menuItems[v_c02].getElementsByTagName('description')[0].firstChild.data;
            v_str += '","';
            if (v_menuItems[v_c02].getElementsByTagName('submenu')[0].firstChild != null)
            v_str += v_menuItems[v_c02].getElementsByTagName('submenu')[0].firstChild.data;
            v_str += '","'
            if (v_menuItems[v_c02].getElementsByTagName('instruction')[0].firstChild != null)
            v_str += v_menuItems[v_c02].getElementsByTagName('instruction')[0].firstChild.data;
            v_str += '"));';
            eval(v_str);
            }
        }
    // Now hook the submenus onto their their masters
    for (v_c01 = 0; v_c01 < v_menuRows.length; v_c01++) 
        {
        var v_menuItems = v_menuRows[v_c01].getElementsByTagName('MENU_ITEMS');
        for (v_c02 = 0; v_c02 < v_menuItems.length; v_c02++)
            {
            if (v_menuItems[v_c02].getElementsByTagName('submenu')[0].firstChild != null &&
                v_menuItems[v_c02].getElementsByTagName('submenu')[0].firstChild.data != '')
               {
               var v_str  = '';
               v_str += v_menuRows[v_c01].getElementsByTagName('name')[0].firstChild.data;
               v_str += '.items.';
               v_str += v_menuItems[v_c02].getElementsByTagName('submenu')[0].firstChild.data;
               v_str += '.setSubMenu('
               v_str += v_menuItems[v_c02].getElementsByTagName('submenu')[0].firstChild.data;
               v_str += 'menu);';
               eval(v_str);
               }
            }
        }
    eval('setPopUpMenu('+v_menuRows[0].getElementsByTagName('name')[0].firstChild.data+');');
    }
  } 
  }

} 

////////////////////////////////////////////////////////////////////////////////
// This function will be started for every page that includes its_scripts.js
////////////////////////////////////////////////////////////////////////////////
function ITSinit(){
  if (document.createElement && document.getElementById) {
    createjsDOMenu();
  }
}
////////////////////////////////////////////////////////////////////////////////
// Upload the following .js files
////////////////////////////////////////////////////////////////////////////////
//147569 start
//itsUploadCSSfile('/itsincludes/css/jsdomenu.css');
//itsUploadJSfile('/itsincludes/js/its_general.js');
//itsUploadJSfile('/itsincludes/js/jsdomenu.js');

//window.onload=ITSinit; // TODO: What happens if window already has an "onload" event?
//147569  end

//
function run_lov_bind(formName,itemName,itemDesc,theFilter,
                      lovCode,lovParms,showCode,chkSum,codeHeading,
                      descHeading,returnRow)
 {
  if (returnRow == undefined) 
     { 
      returnRow = "-1"; 
     }
  if (codeHeading == undefined)
     {
      codeHeading = "Code";
     }
  if (descHeading == undefined)
     {
      descHeading = "Description";
     }
  frmLOV = open("web.w01pkg.w01_lov_bind" +
                "?X_THEFILTER="  + escape(theFilter) +
                "&X_FORM_NAME="  + escape(formName) +
                "&X_ITEM_NAME="  + escape(itemName) +
                "&X_ITEM_DESC="  + escape(itemDesc) +
                "&X_LOVCODE="    + escape(lovCode) +
                "&X_LOVPARMS="   + escape(lovParms) +
                "&X_SHOWCODE="   + escape(showCode) +
                "&X_CHKSUM="     + escape(chkSum) +
                "&X_CODE_HEADING=" + escape(codeHeading)+
                "&X_DESC_HEADING=" + escape(descHeading)+
                "&X_RETURN_ROW=" + escape(returnRow)+
                "&X_CALLER_URL=" + escape(location.protocol + "//" +
                                          location.host + location.pathname +
                                          location.search),
                "winLOV", 
                "scrollbars=yes,resizable=yes,width=450,height=400");
  window.frmLOV.focus();
  if (frmLOV.opener == null) 
     { 
      frmLOV.opener = self; 
     }
}
function run_lov_bind_jsp(formName,itemName,itemDesc,theFilter,
                          lovCode,lovParms,showCode,chkSum,theDad,codeHeading,
                          descHeading,returnRow)
 {
  if (returnRow == undefined) 
     { 
      returnRow = "-1"; 
     }
  if (codeHeading == undefined)
     {
      codeHeading = "Code";
     }
  if (descHeading == undefined)
     {
      descHeading = "Description";
     }
  frmLOV = open("/pls/"+theDad+"/web.w01pkg.w01_lov_bind" +
                "?X_THEFILTER="  + escape(theFilter) +
                "&X_FORM_NAME="  + escape(formName) +
                "&X_ITEM_NAME="  + escape(itemName) +
                "&X_ITEM_DESC="  + escape(itemDesc) +
                "&X_LOVCODE="    + escape(lovCode) +
                "&X_LOVPARMS="   + escape(lovParms) +
                "&X_SHOWCODE="   + escape(showCode) +
                "&X_CHKSUM="     + escape(chkSum) +
                "&X_CODE_HEADING=" + escape(codeHeading)+
                "&X_DESC_HEADING=" + escape(descHeading)+
                "&X_RETURN_ROW=" + escape(returnRow)+
                "&X_CALLER_URL=" + escape(location.protocol + "//" +
                                          location.host + location.pathname +
                                          location.search),
                "winLOV", 
                "scrollbars=yes,resizable=yes,width=450,height=400");
  window.frmLOV.focus();
  if (frmLOV.opener == null) 
     { 
      frmLOV.opener = self; 
     }
}
