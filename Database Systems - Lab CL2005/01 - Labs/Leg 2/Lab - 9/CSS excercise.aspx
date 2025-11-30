<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Currency Converting Web Site</title>
    <style>
        body {
            font-family: 'Malgun Gothic';
            font-size: 1em; /* normal size text */
            color: purple;
            background-color: grey;
        }
        h1 {
            font-family: 'Microsoft JhengHei';
            color: blue;
        }
        .buttonCSS {
            height: 50px;
            color: blue;
            background-color: transparent;
            border: 3px solid blue;
            border-radius: 25px; /* for rounded edges */
            box-shadow: 0 0 10px blue; /* for border glow */
        }
        .resetButtonCSS {
            height: 50px;
            color: red;
            background-color: transparent;
            border: 3px solid red;
            border-radius: 25px; /* for rounded edges */
            box-shadow: 0 0 10px red; /* for border glow */
        }
        .textBoxCSS, .dropDownCSS {
            border: 2px solid blue;
            border-radius: 5px; /* for less rounded edges */
            box-shadow: 0 0 10px green; /* for border glow */
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Currency Converting Web Site</h1>
            <p>Select Currency Medium:</p>
            <select class="dropDownCSS">
                <option value="select">Select</option>
                <option value="dollar">Dollar</option>
                <option value="euro">Euro</option>
                <option value="pound">Pound</option>
            </select>
            <br />
            <p>Please Enter amount in Rupees to Convert to your Selected Medium:</p>
            <input type="text" class="textBoxCSS"/>
            <br />
            <br />
            <input type="button" class="buttonCSS" value="Convert Rupees To Selected Medium" />
            <br />
            <p>Amount from Rupees to your chosen medium:</p>
            <input type="text" class="textBoxCSS" />
            <br />
            <p>Please enter amount in your chosen medium to convert to Rupees:</p>
            <input type="text" class="textBoxCSS" />
            <br />
            <input type="button" class="buttonCSS" value="Convert from Selected Medium to Rupees" />
            <br />
            <p>Amount from your chosen medium to Rupees:</p>
            <input type="text" class="textBoxCSS" placeholder="" />
            <br />
            <p>Your Previous Chosen Medium was:</p>
            <input type="text" class="textBoxCSS" placeholder="" />
            <br />
            <p>Programmed by:</p>
            <input type="text" class="textBoxCSS" placeholder="" />
            <br />
            <input type="reset" class="resetButtonCSS" value="Reset" />
        </div>
    </form>
</body>
</html>
