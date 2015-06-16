/*

给定一个表Logs：
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+

要求返回连续三次及以上出现的数字。
使用变量来实现。首先定义变量，然后遍历Logs，最后输出。不知为啥没有被通过，一直内部错误。


下面一段是讨论区的代码，已经通过，思路差不多
*/

select
    distinct Num
from (
    select Num, IF(Num = @lastNum, @continueCount := @continueCount+1, @continueCount := 1) as Count, @lastNum := Num
    from Logs , (SELECT @lastNum:=NULL, @continueCount:=0) AS yy
) as CountTable
where CountTable.Count >=3;


SELECT
    DISTINCT Num
FROM (
    SELECT 
        CASE WHEN Num=@prevnum THEN @count:=@count+1 ELSE @count:=1 END,
        CASE WHEN @count>=3 THEN Num ELSE NULL END AS Num,
        @prevnum:=Num
    FROM Logs, (SELECT @prevnum:=NULL, @count:=0) AS A
) AS B
WHERE Num IS NOT NULL

