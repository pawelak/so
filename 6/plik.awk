{ for ( i=1 ; i<=NF ; i++)  x[i] += $i } END { for ( i in x ) printf x[i] " " } 
