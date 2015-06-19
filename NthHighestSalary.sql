
/*

要求返回Employee表中第n高的薪水。
存储过程，传入一个参数N，然后先select Salary
再Order By
最后 limit M,1(LIMIT的意义是，去第M个开始，连续1个)

*/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT M, 1
  );
END
