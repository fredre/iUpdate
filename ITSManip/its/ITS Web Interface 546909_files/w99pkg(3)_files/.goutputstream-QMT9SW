function PopUp(pagename, w, h) {
  var winl = (screen.width - w) / 2;
  var wint = (screen.height - h) / 2;
  winprops = 'height='+h+',width='+w+',top='+wint+',left='+winl+',scrollbars=1,resizable'
  win = window.open(pagename, "PopWindow01", winprops)
  if (parseInt(navigator.appVersion) >= 4) { win.window.focus(); }
}

document.write('<TABLE BORDER="0" WIDTH="100%" CELLSPACING="0" CELLPADDING="0">');
document.write('<TR>');
document.write('<TD VALIGN="middle" ALIGN="center" BGCOLOR="#636563" HEIGHT="27" CLASS="customfooter">');
document.write('[&nbsp;');
// =============================================================================
// Do Not change before this line
// =============================================================================

// New Mailto Entry ------------------------------------------------------------
MT_dest = "croucampm@tut.ac.za";
MT_desc = "Contact Us";
document.write('<A CLASS=\'custfooterlink\' HREF="mailto:'+MT_dest+'">'+MT_desc+'</a>');

// New NON-PopUp Screen Entry --------------------------------------------------
// PU_dest = "http://www.its.co.za";
// PU_desc = "Its";
// document.write('&nbsp;|&nbsp;<A CLASS=\'custfooterlink\' HREF=\''+PU_dest+'\' TARGET=_top>'+PU_desc+'</A>');

// New PopUp Screen Entry ------------------------------------------------------
PU_h = 600;
PU_w = 800;
PU_dest = "http://www.tut.ac.za";
PU_desc = "About Us";
document.write('&nbsp;|&nbsp;<A CLASS=\'custfooterlink\' HREF=\'JavaScript: PopUp("'+PU_dest+'", '+PU_w+', '+PU_h+');\'>'+PU_desc+'</A>');

// New PopUp Screen Entry ------------------------------------------------------
PU_h = 600;
PU_w = 800;
PU_dest = "/itsdocs/disclaimer.html";
PU_desc = "Disclaimer";
document.write('&nbsp;|&nbsp;<A CLASS=\'custfooterlink\' HREF=\'JavaScript: PopUp("'+PU_dest+'", '+PU_w+', '+PU_h+');\'>'+PU_desc+'</A>');

// New PopUp Screen Entry ------------------------------------------------------
PU_h = 600;
PU_w = 800;
PU_dest = "/itsdocs/terms.html";
PU_desc = "Terms &amp; Conditions";
document.write('&nbsp;|&nbsp;<A CLASS=\'custfooterlink\' HREF=\'JavaScript: PopUp("'+PU_dest+'", '+PU_w+', '+PU_h+');\'>'+PU_desc+'</A>');

// New PopUp Screen Entry ------------------------------------------------------
PU_h = 600;
PU_w = 800;
PU_dest = "/itsdocs/privacy.html";
PU_desc = "Privacy &amp; Security Statement";
document.write('&nbsp;|&nbsp;<A CLASS=\'custfooterlink\' HREF=\'JavaScript: PopUp("'+PU_dest+'", '+PU_w+', '+PU_h+');\'>'+PU_desc+'</A>');


// =============================================================================
// Do not change beyond this line
// =============================================================================
document.write('&nbsp;]');
document.write('</TD>');
document.write('</TR>');
document.write('</TABLE>');
