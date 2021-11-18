<!DOCTYPE html>
<html>
<body>

<?php  
for($i = 2; $i <= 50; $i++){
	$count = 0;
	for($j = 2; $j <= 7; $j++){
    	if(($i % $j == 0) && ($i != $j)){
        	$count += 1;
        }
    }
    if($count == 0){
    	echo $i.",";
    }
}
?>  

</body>
</html>
