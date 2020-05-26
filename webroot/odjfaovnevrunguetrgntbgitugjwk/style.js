/*!
 * style.js
 * http://givemefive.top/
 *
 * Copyright 2020, huangdatian
 * Date: Fri Feb 13 09:30:43 2020
 */
 function ShowCountDown(jztime,divname) {
    var now = new Date();
	var endDate = new Date(Date.parse(jztime.replace(/-/g, "/")));
    var leftTime=endDate.getTime()-now.getTime();
    var leftsecond = parseInt(leftTime/1000);
    var day1=Math.floor(leftsecond/(60*60*24));
    var hour=Math.floor((leftsecond-day1*24*60*60)/3600);
    var minute=Math.floor((leftsecond-day1*24*60*60-hour*3600)/60);
    var second=Math.floor(leftsecond-day1*24*60*60-hour*3600-minute*60);
    if(day1 < 10){day1 = "0"+day1;}
    if(hour < 10){hour = "0"+hour;}
    if(minute < 10){minute = "0"+minute;}
    if(second < 10){second = "0"+second;}
    var cc = document.getElementById(divname);
    cc.innerHTML = "距离"+engTime+"剩余：<em class='wxmr4'>"+day1+"</em>天<em class='wxml4'>"+hour+"</em>：<em>"+minute+"</em>：<em>"+second+"</em>";
}
var engTime = "2020-12-31";
window.setInterval(function(){ShowCountDown(engTime,'time_b');}, 1000);
 