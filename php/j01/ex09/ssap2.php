#!/usr/bin/php
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

$i = 1;
$j = 0;

if (!$argv[1])
	return(0);

while ($argv[$i])
{
	$tab = ft_split(trim($argv[$i++]));
	foreach ($tab as $value) 
	{
		$mega_tab[$j++] = $value;
	}
}	

natcasesort($mega_tab);
foreach ($mega_tab as $line)
	if (ctype_alpha($line))
		echo $line . "\n";
sort($mega_tab, SORT_STRING);
foreach ($mega_tab as $line)
	if (is_numeric($line))
		echo $line . "\n";
foreach ($mega_tab as $line)
	if (!ctype_alpha($line) && !is_numeric($line))
		echo $line . "\n";
?>