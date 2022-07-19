"use strict";

// https://coderhub.sa/challenges/3adf453a-35c1-4258-beaf-eae8393c4be0/view?language=JavaScript

// BUG: worg answer ...
function isEmail(email) {
  const regex = /^[a-zA-Z]+\S*[@]\S+[.]\S{2,}$/g;
  return regex.test(email);
}

const email = "hos@example.com";
console.log(isEmail(email));
