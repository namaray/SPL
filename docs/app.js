/* ==========================================================================
   SPL Lab Solutions - the small amount of JavaScript the site uses.

   Two jobs:
     1. Colour the C code in every <pre class="code"> block.
     2. Make the "Copy" button copy that block's code.

   The site works fine without this file; it just looks plainer.
   ========================================================================== */

(function () {
  "use strict";

  // ------------------------------------------------------------------------
  // 1. Syntax colouring
  // ------------------------------------------------------------------------

  // Words that C treats specially. Anything here gets the keyword colour.
  var KEYWORDS = [
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", "bool", "true", "false"
  ];

  /*
    One regular expression finds every kind of token in a single pass.
    The order of the alternatives matters: comments and strings come first,
    so that a keyword written inside a comment stays comment-coloured.

      group 1 -> // line comment  or  /* block comment *\/
      group 2 -> "string" or 'c'
      group 3 -> #include and friends, at the start of a line
      group 4 -> a keyword
      group 5 -> a number
  */
  var TOKENS = new RegExp(
    "(\\/\\/[^\\n]*|\\/\\*[\\s\\S]*?\\*\\/)" +
    "|(\"(?:[^\"\\\\\\n]|\\\\.)*\"|'(?:[^'\\\\\\n]|\\\\.)*')" +
    "|(^[ \\t]*#[a-z]+)" +
    "|\\b(" + KEYWORDS.join("|") + ")\\b" +
    "|\\b(\\d+\\.?\\d*)\\b",
    "gm"
  );

  // Wrap each token in a <span> so the stylesheet can colour it.
  function highlight(code) {
    return code.replace(TOKENS, function (match, comment, string, preproc, keyword, number) {
      if (comment) return '<span class="tok-comment">' + comment + "</span>";
      if (string)  return '<span class="tok-string">' + string + "</span>";
      if (preproc) return '<span class="tok-preproc">' + preproc + "</span>";
      if (keyword) return '<span class="tok-keyword">' + keyword + "</span>";
      if (number)  return '<span class="tok-number">' + number + "</span>";
      return match;
    });
  }

  /*
    The page already contains the code as escaped text (& < > are written as
    &amp; &lt; &gt;). Reading .innerHTML gives that escaped form back, which is
    exactly what we want: highlight() only inserts <span> tags around it, so
    writing it back with .innerHTML cannot introduce stray markup.
  */
  var blocks = document.querySelectorAll("pre.code > code");
  for (var i = 0; i < blocks.length; i++) {
    blocks[i].innerHTML = highlight(blocks[i].innerHTML);
  }


  // ------------------------------------------------------------------------
  // 2. Copy buttons
  // ------------------------------------------------------------------------

  function copyCode(button) {
    // The button and the code block live in the same .solution container.
    var block = button.closest(".solution").querySelector("pre.code > code");
    var text = block.innerText;

    function done() {
      button.textContent = "Copied";
      button.classList.add("copied");
      setTimeout(function () {
        button.textContent = "Copy";
        button.classList.remove("copied");
      }, 1500);
    }

    if (navigator.clipboard) {
      navigator.clipboard.writeText(text).then(done, fallback);
    } else {
      fallback();
    }

    // Older browsers, and pages not served over https, have no clipboard API.
    function fallback() {
      var area = document.createElement("textarea");
      area.value = text;
      area.style.position = "fixed";
      area.style.opacity = "0";
      document.body.appendChild(area);
      area.select();
      try { document.execCommand("copy"); done(); } catch (e) { /* give up quietly */ }
      document.body.removeChild(area);
    }
  }

  var buttons = document.querySelectorAll(".copy-button");
  for (var j = 0; j < buttons.length; j++) {
    buttons[j].addEventListener("click", function (event) {
      copyCode(event.currentTarget);
    });
  }
})();
