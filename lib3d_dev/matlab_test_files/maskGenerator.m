clear all
close all
clc 

width = 512
height = 512
offset = 5.5
N = 30;
sphereSize = 4.5;
iteration = 500;
c = 0.5;
initType = 1;
vis = 1;

 p = sphere(N, sphereSize, iteration, c, initType, vis);
 p = p+offset
 mask = zeros(size(p,1)*8,1);
 maskCoef = zeros(size(p,1),8);
  
figure(3)
hold on
 for i = 1:size(p,1)
    temp = p(i,:)
    temp1 = round(temp)
    
    x = [temp(1)-0.5, temp(1)+0.5];
    y = [temp(2)-0.5, temp(2)+0.5];
    z = [temp(3)-0.5, temp(3)+0.5];

    m = 0;
    for j = x
        for k = y
            for l = z
                plot3(floor(j),floor(k),floor(l),'*')
                mask((i-1)*8 + m +1) = floor(j) + floor(k)*width + floor(l)*width*height;                
                maskCoef(i,m+1) =  abs(j-temp1(1))*abs(k-temp1(2))*abs(l-temp1(3));
                m = m + 1;
            end
        end
    end
 end