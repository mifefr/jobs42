<?php

function ft_strlen($str)
{
	$i = 0;

	while ($str[$i] != NULL)
		$i++;
	return ($i);
}

function ft_split($str)
{
	$str = trim($str);
	$str = str_replace("\t", " ", $str);
	$str = eregi_replace("[ ]+", " ", $str);
	$array = array_filter(explode(" ", trim($str)), "ft_strlen");
	sort($array, SORT_REGULAR);
	return $array;
}
?>
