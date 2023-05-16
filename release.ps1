# Use this Powershell script to push releases
$version = "v1.7.1" 
$commit  = "add comments and test unix builds" 
Write-Output $version > version.tag
git add . && git commit -m "$commit" && git push origin && gh release create $version --title "$version" --notes "$commit"