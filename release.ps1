# Use this Powershell script to push releases
$version = "v1.5.1" 
$commit  = "libconst dependency updated" 
Write-Output $version > version.tag
git add . && git commit -m "$commit" && git push origin && gh release create $version --title "$version" --notes "$commit"