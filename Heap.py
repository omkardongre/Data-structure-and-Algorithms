
#Heap data structure using list
#Heap is "Almost Complete Binary tree" so it implement using array to save space, but for visualization we draw in tree manner.
#Insertion and  Deletion  in log(n) time
#Insertion from last node and deletion from first node always

class maxheap:
    def __init__(self):
        self.data=[]
        self.size=0
         
    def __len__(self):
        return len(self.data)
        
    def insert(self,value):
        
        self.data.append(value)
        self.size+=1
        #parent index
        pindex=( self.size-2 )//2
        #current index
        index=self.size-1
        while index>=1 and value>self.data[pindex]:
            self.data[index]=self.data[pindex]
            index=pindex
            pindex=(pindex-1)//2
        
        self.data[index]=value
        print(self.data)
    
    
    def maxh(self):
  
        if self.data:
            return self.data[0]

    def delete(self):
        
        if not self.size:
            return
        #last value
        lval=self.data.pop()
        self.size-=1
        curr=0

        #left and right index
        lp=1
        rp=2
        while rp<= self.size-1:
            if self.data[lp]>self.data[rp]:
                self.data[curr]=self.data[lp]
                curr=lp
            
            else:
                self.data[curr]=self.data[rp]
                curr=rp
            
            lp=curr*2+1
            rp=curr*2+2

        if self.data:    
            self.data[curr]=lval
        
        if lp<=self.size-1 and self.data[lp]>lval:
            self.data[curr]=self.data[lp]
            self.data[lp]=lval
        
            
                
mobj=maxheap()
#insertion
mobj.insert(5)
mobj.insert(6)
mobj.insert(1)
mobj.insert(9)
mobj.insert(8)
mobj.insert(2)

#max element or root element
mobj.maxh()

mobj.delete()




--------------------------------------------------------------------------------------------------------------




class minHeap:
    def __init__(self):
        self.data=[]
        self.size=0

    def minh(self):
        if self.data:
            return self.data[0]
        
    def insert(self,value):
        self.data.append(value)
        self.size+=1
        
        pindex=(self.size-2)//2
        index=self.size-1
        while index>=1 and self.data[pindex]>value:
            self.data[index]=self.data[pindex]
            index=pindex
            pindex=(pindex-1)//2
            
        self.data[index]=value
        
        print(self.data)
        
    def delete(self):
        if not self.size:
            return
        
        value=self.data.pop()
        self.size-=1
        curr=0
        lp=1
        rp=2
        while rp<=self.size-1:
            if self.data[lp]>self.data[rp]:
                self.data[curr]=self.data[rp]
                curr=rp
            else:
                self.data[curr]=self.data[lp]
                curr=lp
        
            lp=curr*2+1
            rp=curr*2+2
      
        if self.data:
            self.data[curr]=value
        
        if lp<= self.size-1 and self.data[lp]<value:
            self.data[curr]=self.data[lp]
            self.data[lp]=value
        
        print(self.data)


mobj=minHeap()
mobj.insert(5)
mobj.insert(9)
mobj.insert(1)
mobj.insert(6)
mobj.insert(8)
mobj.insert(2)

#root element or minimum element
mobj.minh()

mobj.delete()
