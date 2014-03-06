function saveMaskToJSON(type, maskSize, pointsNum, points, coefs, center, filename)

f = fopen(filename,'w')

fprintf(f,'{ "mask": {\n')
fprintf(f,'\t "type": "%2s",\n', type)
if((strcmp(type,'2d')) || (strcmp(type,'2D'))) 
    fprintf(f,'\t "size": [ %u, %u ],\n', maskSize(1),maskSize(2))   
else
    fprintf(f,'\t "size": [ %u, %u, %u ],\n', maskSize(1),maskSize(2),maskSize(3))
end
fprintf(f,'\t "pointsNum": %u,\n', pointsNum)
fprintf(f,'\t "points": [ ')
for i = 1:size(points)
  fprintf(f,'%u', points(i))
  if(i ~= size(points,1))
    fprintf(f,', ')  
  else
      fprintf(f,'],\n')      
  end
end
fprintf(f,'\t "coefs": [ ')
for i = 1:size(coefs,1)
  fprintf(f,'%f', coefs(i))
  if(i ~= size(coefs,1))
    fprintf(f,', ')   
  else
      fprintf(f,'],\n')       
  end
end
fprintf(f,'\t "center": %u\n', center)
fprintf(f,'}}')
fclose(f)
end
