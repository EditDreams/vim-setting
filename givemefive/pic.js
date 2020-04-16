function lookimg(str)
{
	var newwin=window.open()
	myimg=newwin.document.createElement("img")
	myimg.src=str
	newwin.document.body.appendChild(myimg)
}