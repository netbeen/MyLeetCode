/*

给定表Customers:
+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+

表Orders:
+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+


要求给出从来不下单的用户名字：
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

分析：采用连接语法。其实内部隐含了要求保留全部左边信息的要求（因为如果不保留，没有订单的用户在连接的时候就已经被筛选掉了）
先左外连接，再筛选。
*/
select Name as Customers from Customers left outer join Orders on Customers.Id=Orders.CustomerId where CustomerId is NULL
