function imgOut = imageToLbp(imgIn, type, radius, samples)
% Funkce vytvori lbp reprezentaci obrazku predaneho v parametru img a vraci
% obrazek v LBP reprezentaci
% Volani : imgOut = imageToLbp(imgIn, type, radius, samples)
% Type : 1 - klasicke LBP,2 - uniform, 3 - 5 RotMin 8 - 32 bit

type = type + 15;
pdata = libpointer('doublePtr',imgIn);
t = calllib('lbp','imageToLbp',size(imgIn,1),size(imgIn,2),pdata, type, radius, samples);
imgOut = get(pdata,'Value');