def soli(arr,n,an):
    ans = 0
    for i in range(1,n+1):
        if(ans>=an):
            return ans
        for j in range(i-1,n):
            if(arr[j]==i):
                if(j==i-1):
                    break
                ans+=1
                arr[j],arr[i-1]=arr[i-1],arr[j]
                break
    return ans

def sola(arr,n,an):
    ans = 0
    for i in range(n,0,-1):
        if(ans>=an):
            return ans
        for j in range(0,n):
            if(arr[j]==i):
                if(j==n-i):
                    break
                ans+=1
                arr[j],arr[n-i]=arr[n-i],arr[j]
                break
    return ans


if __name__ == "__main__":
    while(True):
        n=int(input())
        if(n==0):
            break
        arr=input()
        arr=list(map(int,arr.split()))
        ra=[]
        p=0
        for i in range(0,n):
            if(i<p):
                continue
            a=n
            if(i+2<n):
                for j in range(i+2,n):
                    if(arr[j]-arr[j-1]!=arr[j-1]-arr[j-2]):
                        a=j-1
                        break
                ra.append(i)
                ra.append(a)
                p=a+1
            else:
                ra=ra+list(range(i,n))
                break
        ans = 0x7fffffff
        arr=arr+arr
        for i in ra:
            te=list(arr[i:i+n])
            ans = min(ans,soli(te,n,ans))
            te=list(arr[i:i+n])
            ans = min(ans,sola(te,n,ans))
        print(ans)