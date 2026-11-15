docment.getElementById("Gamebtn").addEventListener('click', function() {
    window.open(url, windowName, windowFeatures);

    const url = "https://www.onlinegdb.com/PbJuMaJJw";
    const windowName = "CatCafe";
    const windowFeatures = "width=600,height=400,left=50%,top=80%,rezisable=yes,scrollbar=yes";
    
    const popup = window.open(url, windowName, windowFeatures);

    if(!popup || popup.closed || typeof popup.closed === "undefined") {
        alert("Popup was blocked! Please allow popups for this site.")
    }
});
    