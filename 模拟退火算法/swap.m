function [ newpath,position]=swap(oldpath ,number)  
%��oldpath���л�������
%number Ϊ��������·���ĸ���
%positionΪ��Ӧnewpath������λ��
m=length(oldpath);%���еĸ���
newpath=zeros(number,m);
position=sort(randi(m,number,2),2);%�����������λ��
for i=1:number
    newpath(i,:)=oldpath;%����·����ѡ�еĳ���
    newpath(i,position(i,1))=oldpath(position(i,2));
 newpath(i,position(i,2))=oldpath(position(i,1));
end