clear all
close all
clc 

% Mask settings
width = 9;
height = 9;
N = 8; % Number of points
sphereSize = 4; % radius of sphere
offset = sphereSize; 
iteration = 500;
c = 0.5; % Coeficient (IF N GROWS -> c FALLS)
initType = 1; % Point init algorithm (1 - NON-RANDOM, 0 - RANDOM)
vis = 0; % Visualization

p = sphere(N, sphereSize, iteration, c, initType, vis); % CREATE SPHERE POINTS

% CREATING MASK
pmin = min(min(p))
p = p+abs(pmin)+0.5
mask = zeros(size(p,1)*8,1);
maskCoef = zeros(size(p,1)*8,1);

if (vis == 1)
	figure(3)
	hold on
end
 for i = 1:size(p,1)
    temp = p(i,:);
    temp1 = round(temp);
    
    x = [temp(1)-0.5, temp(1)+0.5];
    y = [temp(2)-0.5, temp(2)+0.5];
    z = [temp(3)-0.5, temp(3)+0.5];

    m = 0;
    for j = x
        for k = y
            for l = z
            	  if (vis == 1)
                	plot3(floor(j),floor(k),floor(l),'*')
                end
                mask((i-1)*8 + m +1) = floor(j) + floor(k)*width + floor(l)*width*height;                
                maskCoef((i-1)*8 + m +1) =  abs(j-temp1(1))*abs(k-temp1(2))*abs(l-temp1(3));
                m = m + 1;
            end
        end
    end
 end
 
center = (((2*sphereSize+1)*(2*sphereSize+1)*(2*sphereSize+1))/2)+0.5;
 
% SAVING MASK
saveMaskToJSON('3D', [4,4,4], N, mask , maskCoef, center, 'mask3D_8.json')
