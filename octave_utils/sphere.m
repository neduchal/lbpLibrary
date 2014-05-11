function [points] = sphere(N, sphereSize, iterations, c, initType, vis)
% c = 0.5;
% iterations = 500;
% N = 200;
% initType = 1;

if initType == 1
points = InitPoints(N,c,1);
else
    for i = 1:N
        points(i,:) = -1+ 2 .* rand([1,3]);
        normp = norm(points(i,:));
        points(i,:) = points(i,:)./normp;
    end
end

if vis == 1
    figure(2)
    plot3(points(:,1), points(:,2), points(:,3), '*')
end

for i = 1:iterations
    for j = 1:N
        mindist = 100000000;
        minindex = 0;

        actualdist = zeros(N,1);
        for k = 1:N
            if j == k
                actualdist(k) = 1000;
                continue;
            end
            actualdist(k) = norm(points(j,:) - points(k,:));         
        end

        [mindist, minindex] = min(actualdist);
        actualdist(minindex) = 1000000;
        
        for l = 1:4
            [ddist, dindex] = min(actualdist);    
             actualdist(dindex) = 1000000; 
        end
        
        maxmindist = min(actualdist);
        
        minvector = points(minindex,:) - points(j,:);
        points(j,:) = points(j,:) - c*(1 - (mindist/maxmindist))*minvector;
        normp = norm(points(j,:));
        points(j,:) = points(j,:)./normp;        
    end
end
points = points.*sphereSize;
 
if vis == 1
    figure(1)
    plot3(points(:,1), points(:,2), points(:,3), '*')
end

end
