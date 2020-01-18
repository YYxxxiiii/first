function [ newpath,position]=swap(oldpath ,number)  
%对oldpath进行互换操作
%number 为产生的新路径的个数
%position为对应newpath互换的位置
m=length(oldpath);%城市的个数
newpath=zeros(number,m);
position=sort(randi(m,number,2),2);%随机产生交换位置
for i=1:number
    newpath(i,:)=oldpath;%交换路径中选中的城市
    newpath(i,position(i,1))=oldpath(position(i,2));
 newpath(i,position(i,2))=oldpath(position(i,1));
end