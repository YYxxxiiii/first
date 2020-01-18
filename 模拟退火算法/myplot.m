function[]=myplot(path,coord,pathfar)%做出路径的图形 
%path为要做图的路径，coord为各个城市的坐标
%pathfar为路径path对应的费用
len = length(path);
clf;
hold on;
title(['近似最短路径如下，路径为',num2str(pathfar)]);
plot(coord(1,:),coord(2,:),'ok');
pause(0.4);
for ii = 2:len
plot(coord(1,path([ii-1,ii])),coord(2,path([ii-1,ii])),'-k');
x= sum(coord(1,path([ii-1,ii])))/2;
y= sum(coord(2,path([ii-1,ii])))/2;
text(x,y,['(', num2str(ii-1),')']);
pause(0.4);
end
plot(coord(1,path([1,len])),coord(2,path([1,len])),'-k');
x= sum(coord(1,path([1,len])))/2;
y= sum(coord(2,path([1,len])))/2;
text(x,y,['(', num2str(len),')']);
pause(0.4);
hold off;