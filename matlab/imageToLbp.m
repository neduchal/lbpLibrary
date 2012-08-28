function imgOut = imageToLbp(imgIn, type, radius, samples)
% Funkce vytvoøí lbp reprezentaci obrázku pøedaného v parametru img a vrací
% obrázek v LBP reprezentaci
% Volání : imgOut = imageToLbp(imgIn, type, radius, samples)
% Type : 1 - klasicke LBP,2 - uniform, 3 - 5 RotMin 8 - 32 bit

type = type + 15;
pdata = libpointer('doublePtr',imgIn);
t = calllib('lbp','imageToLbp',size(imgIn,1),size(imgIn,2),pdata, type, radius, samples);
imgOut = get(pdata,'Value');