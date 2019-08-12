const getNic = document.getElementById("nic");
//const btnSubmit = document.getElementById("submit");
const btnReset = document.getElementById("reset");
const form = document.getElementById("form");
const display = document.getElementById("display");
const displayNic = document.getElementById("displayNic");
const displayDob = document.getElementById("displayDob");
const displaySex = document.getElementById("displaySex");

form.addEventListener("submit", function(e) {
    e.preventDefault();
    let nic = getNic.value;
    let year;
    let month;
    let day;
    let sex;
    if (!checkNIC(nic))
    {
        alert("Invalid NIC")
    } else
    {
        year = getYear(nic);
        day = getday(nic);
        sex = getSex(day);
        day = setday(day);
        month = getMonth(day);
        day = getDate(day);
        
        displayNic.innerText = nic;
        displayDob.innerText = day + " " + month + " " + year;
        displaySex.innerText = sex;

        display.style.display = "block";
    }
});

btnReset.addEventListener("click", function() {
    getNic.value = "";
    display.style.display = "none";
});

function checkNIC(nic) {
    if (nic.length == 9 || nic.length == 12)
    {
        return true;
    } else
    {
        return false;
    }
}

function getYear(nic)
{
    if (nic.length == 9)
    {
        return "19" + nic.substring(0,2);
    } else
    {
        return nic.substring(0,4);
    }
}

function getday(nic)
{
    if (nic.length == 9)
    {
        return nic.substring(2,5);
    } else
    {
        return nic.substring(4,7);
    }
}

function getSex(day)
{
    if ( day > 500 )
    {
        return "Female";
    } else
    {
        return "Male";
    }
}

function setday(day)
{
    if ( day > 500 )
    {
        return day - 500;
    } else
    {
        return day;
    }
}

function getMonth(day)
{
    let month;

    if (day > 335)
    {
        month = "December";
    } else if (day > 305)
    {
        month = "November";
    } else if (day > 274)
    {
        month = "October";
    } else if (day > 244)
    {
        month = "September";
    } else if (day > 213)
    {
        month = "August";
    } else if (day > 182)
    {
        month = "July";
    } else if (day > 152)
    {
        month = "June";
    } else if (day > 121)
    {
        month = "May";
    } else if (day > 91)
    {
        month = "April";
    } else if (day > 60)
    {
        month = "March";
    } else if (day > 31)
    {
        month = "February";
    } else
    {
        month = "January";
    }

    return month;
}

function getDate(day)
{
    if (day > 335)
    {
        day = day - 335;
    } else if (day > 305)
    {
        day = day - 305;
    } else if (day > 274)
    {
        day = day - 274;
    } else if (day > 244)
    {
        day = day - 244;
    } else if (day > 213)
    {
        day = day - 213;
    } else if (day > 182)
    {
        day = day - 182;
    } else if (day > 152)
    {
        day = day - 152;
    } else if (day > 121)
    {
        day = day - 121;
    } else if (day > 91)
    {
        day = day - 91;
    } else if (day > 60)
    {
        day = day - 60;
    } else if (day > 31)
    {
        day = day - 31;
    }

    return day;
}
