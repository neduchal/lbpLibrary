function histogram = realTimeLbp(img)
% Funkce vytvoøí lbp reprezentaci obrázku pøedaného v parametru img a vrací
% histogram tohoto obrázku
% Volání : histogram = imageToLbpR(img)

pdata = libpointer('int32Ptr',img);
res = int32(1:256);
pdata2 = libpointer('int32Ptr',res);
t = calllib('reallbp','RealTimeLbp',size(img,1),size(img,2),pdata, pdata2);
histogram = get(pdata2,'Value');