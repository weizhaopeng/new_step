list1 = ['nihao', 1, 1.2];
print(list1);

print("the last element is:"+str(list1[-1]));

list1.append('weizhaopeng');
print(list1);

list1.insert(1, 'jiao');
print(list1);

del list1[3];
print(list1);

temp = list1.pop();
print(list1);

list1.remove('jiao');
print(list1);

temp = sorted(list1);
print(temp);
print(list1);

print(list1.sort());

print(len(list1));
print(list1, list1.reverse());
