nums1=[0]*20
print("Number of input data:")
num=int(input())
for i in range(num):
    print("Input:")
    nums1[i]=int(input())
print("Input k:")
k=int(input())
print("Input m:")
m=int(input())
nums2=nums1[0:m]+[k]+nums1[m:num]
print("list 1:",nums1[0:num])
print("list 2:",nums2)