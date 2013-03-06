// ################################################################
// System           : WEB SYSTEMS
// Program name     : its_menu.js
// Description      : Logic to handle the menu movements in the web system
// Date created     : 01-jan-2002 Ollie
// Date changed     : 13-MAY-2004 109706 Ollie Add Auto Navigate logic
// Date changed     : 21-JUN-2004 111948 Ollie Do not hide any menus 
// Date changed     : 03-MAR-2009 149649 Ollie Add GUESTLIBR and GUESTOTHR logic
// Versions         : v01.0.0.1
// Copyright        : Integrated Tertiary Software 01-JAN-1987
// ################################################################

var ie=document.all?1:0
var ns6=document.getElementById&&!document.all?1:0
var ns4=document.layers?1:0
var oldIndx=0;      // Array index of previously highlighted option
var oldColr='';     // Original Colour of highlighted option
var oldInterval=0;  // interval used to highlight current option

var startMenu=0 // Level at which to start menus
var allMenus="Y"  // Should all level of menus be printed

var topimg=new Image()
topimg.src="/itsimages/top.gif"
var minus2img=new Image()
minus2img.src="/itsimages/icomin.gif"
var plus2img=new Image()
plus2img.src="/itsimages/icoplus.gif"
var helpimg=new Image()
helpimg.src="/itsimages/icoquest.gif"

var minusimg=new Image()
minusimg.src="/itsimages/icomin.gif"
var plusimg=new Image()
plusimg.src="/itsimages/icoplus.gif"
var emptyimg=new Image()
emptyimg.src="/itsimages/join.gif"

var plusmin=new Array(minusimg.src,plusimg.src,emptyimg.src)
var plusminalt=new Array("Close This Menu", "Open This Menu", "")

function highLightIt(Nbr){
if (document.getElementById){
if (document.getElementById("menuId"+Nbr).style.color!="red")
document.getElementById("menuId"+Nbr).style.color="red";
else
document.getElementById("menuId"+Nbr).style.color='';
}
}
function GuestLogin(pagename, windowname, w, h) {
  window.top.name="iEnablerGuestWindow";
  var winl = (screen.width - w) / 2;
  var wint = (screen.height - h) / 2;
  winprops = 'height='+h+',width='+w+',top='+wint+',left='+winl+',menubar=no,scrollbars=0,resizable=no,status=no,directories=no'
  win = window.open(pagename, windowname, winprops)
  if (parseInt(navigator.appVersion) >= 4) { win.window.focus(); }
   return false;
}

var content=""



function init() {
gen_menu();

if (ie || ns6) {
document.write('<div id="menu" style="position:relative">'+content+'</div>')
document.close()
}
else if (ns4) {
document.write('<ILAYER id="menutop">')
document.write('<LAYER id="menu">'+content+'</LAYER>')
document.write('</ILAYER>')
document.close()
}
else {
oldbrowser();
}

return;
} // end function init
function oldbrowser() {
document.write('This is an old browser. Please Upgrade')
document.close
} // end function oldbrowser


// ==================================================================
// this function will print the content onto the screen
function refresh_menu() {
if (ie) {
menu.innerHTML=content
}
if (ns6) {
document.getElementById("menu").innerHTML=content
}
if (ns4) {
document.menutop.document.menu.document.write(content)
document.menutop.document.menu.document.close()
}
return;
} // end function refresh_menu


// ==================================================================
// This function will physically run the chosen command
function run_menu(thislevel) {
var selectedtarget=i_target[thislevel]
var selectedurl=i_url[thislevel]
var selectedind=i_ind[thislevel]

if (selectedurl!="#" && selectedurl!="" && selectedurl!="http://" && selectedurl.indexOf("@")<0) {
 if (selectedind=="M") {
 // ollie //startMenu=thislevel
 // ollie //allMenus="N"
 // ollie //i_open[thislevel]=0 
 var j=2
 if (i_open[thislevel]==0) { j=1 }
 if (i_open[thislevel]==1) { j=0 }
 i_open[thislevel]=j;
 gen_menu()
 refresh_menu()
 }
}
if (selectedurl.substr(0,25) == "w99pkg.mi_validate_option") {
parent.F3.location.replace(selectedurl);
}
} // end function run_menu


// ==================================================================
// This function open/close the menu levels
function do_plusmin(thislevel) {
var j=2
if (i_open[thislevel]==0) { j=1 }
if (i_open[thislevel]==1) { j=0 }
i_open[thislevel]=j;
gen_menu();
refresh_menu();

// ollie //
if (i_ind[thislevel] == "M" &&   // If this is a Menu
    i_open[thislevel] == 0  &&   // And this menu is open
    i_auto[thislevel] == 'Y')    // And this menu is an auto navigate menu
   {
   UnderLineThis(thislevel+1);
   }

return;
} // end function do_plusmin


// ==================================================================
// This function will setup the HTML text to display
function gen_menu() {
var i=0
var j=0

content=""

// Open and Close All
content+="<table border=0 cellpadding=0 cellspacing=0 width='100%'><tr><td>"
content+="<table border=0 cellpadding=1 cellspacing=1><tr><td>"
// content+="<a href='javascript: reset_all();'><img src='"+topimg.src+"' border=0 width=13 hspace=1 alt='Reset The Menu'></a>"
//content+="<a href='javascript: open_all();'><img src='"+plus2img.src+"' border=0 width=10 hspace=1 alt='Open All The Menus'></a>"
//content+="<a href='javascript: close_all();'><img src='"+minus2img.src+"' border=0 width=10 hspace=1 alt='Close All The Menus'></a>"
content+="</td></tr></table></td></tr><tr><td nowrap>"
print_option(startMenu)

content+="</td></tr><tr><td>"

// T149649
if (i_url[0] == 'GUESTLIBR' || i_url[0] == 'GUESTOTHR')
{
content+="<a href=\"\"";
content+=" target=\"_top\"";
content+=" class=\"menuLvl0\"";
content+=" onMouseOver='javascript:window.status=\"Click Here to Login\"; return true;'";
content+=" onMouseOut='hidestat()'";
content+=" onClick=\"return GuestLogin('w99pkg.guest_login','GuestLogin',600,450);\"";
content+=">Login</a>";
}
else
{
// If you need to reroute to another URI when logging out, use the following:
// content+="<a href='w99pkg.mi_logout?dest=http://reroute_to_this.com' target='_top' class=menuLvl0"
content+="<a href='w99pkg.mi_logout' target='_top' class=menuLvl0"
content+=" onMouseOver='javascript:window.status=\"Logout\"; return true;' onMouseOut='hidestat()'"
content+=">Logout</a>"
}

content+="</td></tr></table>"

//alert(content)
return;
} // end function gen_menu

function showstat(thislevel) {
window.status=i_text[thislevel]
}

function hidestat() {
window.status=""
}

// ==================================================================
// This function will setup each option
// NOTE: this is called recursively
function print_option(strtpoint) {
var i=0
var j=0
var thislevel=0

for (i=strtpoint; i<i_level.length; i++) {
thislevel=i

// Add help button where needed
if (i_help[i]!="") {
content+="<a href='javascript: do_help("+i+");'><img src='"+helpimg.src+"' border=0 width=15 alt='Help'></a>"
} else
{
content+="<img src='"+emptyimg.src+"' border=0 width=15>"

}

// Add indentation
for (j=1;j<=i_level[i];j++) { content+="&nbsp;" }
//for (j=1;j<=i_level[i];j++) { content+="<img src='"+emptyimg.src+"' border=0 width=15>" }

// Add plus/minus button if (M)enu
if (i_ind[i]=="M") {
content+="<a href='javascript: do_plusmin("+i+");' "
content+=" onMouseOver='showstat("+i+"); return true;' onMouseOut='hidestat()'"
content+=" onClick='return mouseDown(event,this,"+i+");'"
content+=">"
}
content+="<img src='"+plusmin[i_open[i]]+"' border="+((i_ind[i]=="U")?"0":"0")+" width=15 alt='"+plusminalt[i_open[i]]+"'>"
if (i_ind[i]=="M") { content+="</a>" }

if (i_ind[i]=="M") {
// Add Menu instruction
// ollie //content+="&nbsp;<a href='javascript:run_menu("+i+");'"
// ollie //content+="&nbsp;<a href='javascript:do_plusmin("+i+");'"
content+="&nbsp;<a href='javascript:do_plusmin("+i+");'"
}
else {
//If this is a javaScript instruction, then call it without a target
if (i_url[i].substring(0,11) == "javascript:")
   {
   content+="<a href='"+i_url[i]+"'"
   }
else
   {
   // Add module call instruction
   content+="<a href='"+i_url[i]+"' target='"+i_target[i]+"'"
   }
}
content+=" class=menuLvl"+i_ind[i]+i_level[i]
content+=" id=menuId"+i
content+=" onMouseOver='showstat("+i+"); return true;' onMouseOut='hidestat()'"
content+=" onClick='return mouseDown(event,this,"+i+");'"
content+=">"
content+=i_text[i]+"</a><br />"

// drildown into this menu
if ((i_ind[i]=="M") && (i_level.length > (i+1)) && (i_level[i] < i_level[i+1])) {
   if (i_open[i]==0) { print_option(i+1) }
   for (j=i+1; (j<i_level.length && i_level[j]>i_level[thislevel]); j++) { i++; }
}
 if ((i_level[thislevel] != i_level[i+1])) { i+=i_level.length }


// Only print this level/menu when requested
if ((allMenus=="N") && (i_level[thislevel]<=i_level[startMenu])) { i+=i_level.length }

} // end main loop
return;
} // end function print_option


function do_help(thislevel) {

PopUp(i_help[thislevel],"helpMenu",800,600);
} // end do_help


function open_all() {
// Now close the menu options
for (i=(i_level.length); i>=0; i--) { if (i_open[i]==1) { i_open[i]=0 } }
gen_menu()
refresh_menu()
}
function close_all() {
// Now close the menu options
for (i=(i_level.length); i>=0; i--) { if (i_open[i]==0) { i_open[i]=1 } }
gen_menu()
refresh_menu()
}
function reset_all() {
// Now close the menu options
for (i=(i_level.length); i>=0; i--) { if (i_open[i]==0) { i_open[i]=1 } }
startMenu=0
allMenus="Y"
gen_menu()
parent.F3.location.replace('w99pkg.mi_frame_main');
parent.F4.document.getElementById("fra_summary").style.display="none";
parent.F4.document.getElementById("fra_footer").style.display="block";
refresh_menu()
}


// Change the footer to describe the process status
function setup_f4_process(idNbr) {

mbf_length=i_url.length;
mbf_max=0;     // Number of maximum business processes
mbf_indx=0;    // Current Business process;
mbf_bfunction=''; //the Business function currently used

mbf_endat=i_url[idNbr].indexOf("&x_seq=");
mbf_bfunction=i_url[idNbr].substring(35,(mbf_endat));
//alert(mbf_bfunction);

//mbf_endat=i_url[0].indexOf("&x_seq="); 
//alert (i_url[0].substring(35,(mbf_endat))+"#"+mbf_bfunction);
for (i=0; i<mbf_length; i++)
    { 
    ////if (i_bfun[i]==i_bfun[idNbr])
    mbf_endat=i_url[i].indexOf("&x_seq=");
    if (i_url[i].substring(35,(mbf_endat))==mbf_bfunction) // If same Bus Function
       {
       mbf_max++;
       if (i==idNbr) { mbf_indx=mbf_max; }
       }
    }
// Deduct count of Main Business Function Call (Not a Process)
mbf_max--;
if (mbf_indx!=1) { mbf_indx--; }

show_F4_process(mbf_indx,mbf_max,i_mand[idNbr])
}


function reverseUnderline() {
if (document.getElementById){
if (document.getElementById("menuId"+oldIndx))
document.getElementById("menuId"+oldIndx).style.textDecoration="none";

oldIndx--;
document.getElementById("menuId"+oldIndx).style.textDecoration="underline";
}
setup_f4_process(oldIndx);
}


function show_F4_process(mbf_indx,mbf_max,mbf_mand) {
mbf_pixels=300; //Max width (number of pixels) when 100% processes completed
//================================================================
mbf_detl='';
mbf_detl='<table border="0" width="100%" cellspacing="0" cellpadding="0"> <tr><td bgcolor="#525552" height="2"><img border="0" src="/itsimages/1x1trans.gif" width="1" height="1"></td></tr> <tr><td bgcolor="#FFFFFF" height="3"><img border="0" src="/itsimages/1x1trans.gif" width="1" height="1"></td></tr> <tr><td bgcolor="#859297" height="1"><img border="0" src="/itsimages/1x1trans.gif" width="1" height="1"></td></tr> </table>'; 
mbf_detl+='<TABLE cellSpacing=0 cellPadding=0 align=left vAlign="TOP" border=0 width="98%">';
mbf_detl+='<TBODY><TR><TD vAlign="TOP" width="'+(mbf_max*(mbf_pixels/mbf_max))+'">';
mbf_detl+='<table cellspacing=0 cellpadding=0 border=2 valign="top" ';
mbf_detl+=' width="'+(mbf_max*(mbf_pixels/mbf_max))+'">';
mbf_detl+='<tr><td>';
mbf_detl+='<IMG height=10 src="/itsimages/hbar_front.gif" width='+(mbf_indx*(mbf_pixels/mbf_max))+'>';
mbf_detl+='</td></tr></table>';
mbf_detl+='</TD><TD class="thisProc">';
if (mbf_mand == "Y")
{ mbf_detl+='&nbsp;&nbsp;(Mandatory Step '+mbf_indx+' of '+mbf_max+')'; }
else
{ mbf_detl+='&nbsp;&nbsp;(Optional Step '+mbf_indx+' of '+mbf_max+')'; }
if (mbf_max != mbf_indx)
   {
   mbf_detl+='</TD><TD class="nxtProc">';
   mbf_detl+='<A href="w01pkg.w01_gonxt" target="F3" ';
   mbf_detl+=' onClick="parent.F1.show_F4_process('+(mbf_indx+1)+','+mbf_max+',\''+mbf_mand+'\');parent.F1.StepUpUnderline();">Next&nbsp;Step</a>';

   }
mbf_detl+='</TD></TR></TABLE>';
//================================================================

// Set the actual detail to display and then display it
parent.F4.document.getElementById("fra_summary").innerHTML='<html><body>'+mbf_detl+'</body></html>';
parent.F4.document.getElementById("fra_summary").style.display="block";
parent.F4.document.getElementById("fra_footer").style.display="none";
}


function hide_F4_process() {
parent.F4.document.getElementById("fra_summary").style.display="none";
parent.F4.document.getElementById("fra_footer").style.display="block";
}


function UnderLineThis(idNbr) {
if (document.getElementById){
if (document.getElementById("menuId"+oldIndx))
document.getElementById("menuId"+oldIndx).style.textDecoration="none";

if (i_ind[idNbr] == "M" && i_open[idNbr] == 0) idNbr++;
oldIndx=idNbr;
document.getElementById("menuId"+oldIndx).style.textDecoration="underline";
}
}


function StepUpUnderline() {
if (document.getElementById){
if (document.getElementById("menuId"+oldIndx))
document.getElementById("menuId"+oldIndx).style.textDecoration="none";

oldIndx++;
document.getElementById("menuId"+oldIndx).style.textDecoration="underline";
}
setup_f4_process(oldIndx);
}


function mouseDown(e,ctl,idNbr) {
 var ctrlPressed=0;
 var altPressed=0;
 var shiftPressed=0;

if (i_ind[idNbr] == "M" && i_open[idNbr] == 1) // Menu and currently closed
   {
   // ollie // i_open[idNbr]=0;
   // ollie // do_plusmin(idNbr);
   // ollie // UnderLineThis(idNbr+1);
   UnderLineThis(idNbr);
   }
else
   {
   UnderLineThis(idNbr);
   }

 if (parseInt(navigator.appVersion)>3) {
  if (navigator.appName=="Netscape") {
   var mString =(e.modifiers+32).toString(2).substring(3,6);
   shiftPressed=(mString.charAt(0)=="1");
   ctrlPressed =(mString.charAt(1)=="1");
   altPressed  =(mString.charAt(2)=="1");
   }
  else {
   shiftPressed=event.shiftKey;
   altPressed  =event.altKey;
   ctrlPressed =event.ctrlKey;
   }

  // If the alt and Ctl key was pressed while user clicked on an option,
  // try to open the version detail in a popup screen
  if (altPressed && ctrlPressed) {
   // Check for "*.startup$"
   var x = /(\w+)(\$\.startup$)/i
   var y = x.exec(ctl);
   if (y == null)
      {
      // Check for "*pkg.*"
      x = /(\w+)(pkg\.)(\w+)/i
      y = x.exec(ctl);
      if (y == null)
         {
         return false;
         }
      else
         {
         var z=y[1]+'pkg.'+y[1]+'_version';
         expWin(z);
         return false;
         }
      }
   else
      {
      var z=y[1]+'$.version';
      // PopUp(z,"VerDet",800,600);
      expWin(z);
      return false;
      }
}
}
// if (i_url[idNbr].substr(0,25) == "w99pkg.mi_validate_option")
// ollie //
if (i_auto[idNbr] == "Y"  // if this is an Auto Navigate Option
&&  i_ind[idNbr]  == "M"  // And this is a menu
&&  i_open[idNbr] == 1)   // And menu is open
   {
   setup_f4_process(idNbr);
   run_menu(idNbr+1);
   }
else
{
if (i_auto[idNbr] == "Y"  // if this is an Auto Navigate Option
&&  i_ind[idNbr]  != "M") // And this is NOT a menu
   {
   setup_f4_process(idNbr);
   }
else
   {
   hide_F4_process();
   }
}

if (i_ind[idNbr] == "M"
&&  i_auto[idNbr]== "N")
   {
   parent.F3.location.replace('w99pkg.mi_frame_main');
   }

if (i_ind[idNbr] == "M"
&&  i_open[idNbr] == 0)   // And menu is open
   {
   parent.F3.location.replace('w99pkg.mi_frame_main');
   }

return true;
}  // end Function mouseDown


function newWin(x_website,x_frameName) {
var windowprops='width=1,height=1,scrollbars=yes,status=yes,resizable=yes'
var leftdist = 20;   // distance to left edge of window
var topdist = 20;    // distance to top edge of window

if (window.resizeTo&&navigator.userAgent.indexOf("Opera")==-1) {
var winwidth = window.screen.availWidth - (leftdist*2);
var winheight = window.screen.availHeight - (topdist*2);
var sizer = window.open("",x_frameName,"left=" + leftdist + ",top=" + topdist +","+ windowprops);
sizer.location = x_website;
sizer.resizeTo(winwidth, winheight);
}
else
window.open(x_website,x_frameName);
} // end Function newWin


function expWin(website) {
var windowprops='width=1,height=1,scrollbars=yes,status=yes,resizable=yes'
var heightspeed = 7; // vertical scrolling speed (higher = slower)
var widthspeed = 9;  // horizontal scrolling speed (higher = slower)
var leftdist = 20;   // distance to left edge of window
var topdist = 20;    // distance to top edge of window

if (window.resizeTo&&navigator.userAgent.indexOf("Opera")==-1) {
var winwidth = window.screen.availWidth - (leftdist*2);
var winheight = window.screen.availHeight - (topdist*2);
var sizer = window.open("","","left=" + leftdist + ",top=" + topdist +","+ windowprops);
sizer.location = website;
for (sizeheight = 1,sizewidth = 1;
     sizeheight < winheight && sizewidth < winwidth;
     sizeheight += heightspeed,sizewidth += widthspeed)
{ sizer.resizeTo("1", sizeheight);
  sizer.resizeTo(sizewidth, sizeheight); }
for (; sizeheight < winheight; sizeheight += heightspeed)
sizer.resizeTo("1", sizeheight);
for (; sizewidth < winwidth; sizewidth += widthspeed)
sizer.resizeTo(sizewidth, sizeheight);
}
else
window.open(website,'mywindow');
} // end Function expWin


function get_value(ckNm) {
  // Return the value for the given cookie or return an empty string
  var regX=new RegExp("\\b" + ckNm + "=([^;]*)");
  var found = regX.exec(document.cookie);
  if (found) return(found[1]); else return("");
}

function loadStartMenu(mnu) {
   document.cookie="Onumtype="+get_value("numtype") +";path=/";
   document.cookie="Ounum="   +get_value("unum")    +";path=/";
   document.cookie="Omenu="   +get_value("menu")    +";path=/";
   document.cookie="menu="    +mnu                  +";path=/";

   parent.document.location.replace("w99pkg.mi_main_menu");
}

function loadOriginalMenu() {
   document.cookie="numtype="+get_value("Onumtype") +";path=/";
   document.cookie="unum="   +get_value("Ounum")    +";path=/";
   document.cookie="menu="   +get_value("Omenu")    +";path=/";

   parent.document.location.replace("w99pkg.mi_main_menu");
}

function SetQueryStudent() {
   SQS_nbr = prompt("Please Enter The Student Number to Query With","");
   document.cookie="numtype="+"S"     +";path=/";
   document.cookie="unum="   +SQS_nbr +";path=/";
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
return true;
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
