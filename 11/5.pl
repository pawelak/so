use strict 'vars';
use strict 'subs';
use warnings;

my @matrix1=
(
    [1, 2, 3], 
    [4, 5, 6],
    [7, 8, 9]
);
my @matrix2=
(
    [2, 4, 6],
    [1, 3, 5], 
    [7, 8, 9]
);

my @product = @{ matrix_multiply(\@matrix1, \@matrix2) };

for (my $i=0;$i le 2;$i++) {
        for (my $j=0;$j le 2;$j++) {
            print $product[$i][$j]," ";
        }
    print "\n";
}



sub matrix_multiply 
{
    my ($r_mat1,$r_mat2)=@_;
    my ($r_product);

	for (my $i=0;$i<3;$i++) 
	{
		for (my $j=0;$j<3;$j++) 
		{
			my $sum=0;
			for (my $k=0;$k<3;$k++) 
			{
				$sum+=$r_mat1->[$i][$k]*$r_mat2->[$k][$j];
			}
			$r_product->[$i][$j]=$sum;
		}
	}
	$r_product;
}


