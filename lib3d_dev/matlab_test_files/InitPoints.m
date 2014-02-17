function [ points ] = InitPoints(N, c, rs)
%INITPOINTS Summary of this function goes here
surface = 4*pi;
pointsurface = surface/N;
r = (pointsurface/pi)^(1/2);

distance = 2*r;

points = zeros(N,4);

points(1,:) = [0,0,1,0];

for i = 1:6
    helpPoint =  points(1,1:3) + [cos((i-1)*pi/3)*distance,sin((i-1)*pi/3)*distance,0];
    helpPoint = helpPoint/norm(helpPoint) ;  
    helpPoint2 = helpPoint - points(1,1:3);      
    helpPoint2 = helpPoint2/norm(helpPoint2);
    for j = 1:10
        helpPoint =  points(1,1:3) + helpPoint2.*distance;
        helpPoint = helpPoint/norm(helpPoint) ;  
        helpPoint2 = helpPoint - points(1,1:3);
        helpPoint2 = helpPoint2/norm(helpPoint2);        
    end
   points(i+1,1:3) = points(1,1:3) + helpPoint2.*distance;
   points(i+1,1:3) = points(i+1,1:3)/norm(points(i+1,1:3)) ;   
   points(i+1,4) = helpPoint(3);
end

ind = 8;
i = 2;
while ind <= N;
    for j = 1:6
        if(ind > N)
           break; 
        end
        if i > N 
            ind = N+1;
            break;
        end
        helpPoint =  points(i,1:3) + [cos((j-1)*pi/3)*distance,sin((j-1)*pi/3)*distance,points(4)];
        helpPoint = helpPoint/norm(helpPoint) ;  
        helpPoint2 = helpPoint - points(i,1:3);      
        helpPoint2 = helpPoint2/norm(helpPoint2);
        for k = 1:20
            helpPoint =  points(i,1:3) + helpPoint2.*distance;
            helpPoint = helpPoint/norm(helpPoint) ;  
            helpPoint2 = helpPoint - points(i,1:3);
            helpPoint2 = helpPoint2/norm(helpPoint2);        
        end
        ok = 1;
        helpPoint = points(i,1:3) + helpPoint2.*distance;
        helpPoint = helpPoint/norm(helpPoint) ;          
        for k = 1:N
            if(k == i)
                continue;
            end
            np = norm(helpPoint - points(k,1:3));
            if(np < c*distance)
               ok = 0 ;
            end
        end
        if(ok == 1)           
            points(ind,:) = [helpPoint, i];
            ind = ind + 1;
        end
    end  
    i = i+1;
end

points2 = points(:,1:3).*rs;
points = points2;

end

