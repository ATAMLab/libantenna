# Use this Powershell script to push releases
$version = "v1.7.0" 
$commit  = "add measurement releated functions" 
Write-Output $version > version.tag
git add . && git commit -m "$commit" && git push origin && gh release create $version --title "$version" --notes "$commit"