{*
 * $Revision: 847 $
 * If you want to customize this file, do not edit it directly since future upgrades
 * may overwrite it.  Instead, copy it into a new directory called "local" and edit that
 * version.  Gallery will look for that file first and use it if it exists.
 *}
<div class="gbBlock gcBackground1">
  <h2> {g->text text="Import Complete"} </h2>
</div>

<div class="gbBlock">
  <h2 class="giSuccess">
    {if ($ImportResults.counts.albumImportSuccess)}
      {g->text one="Successfully imported %d album." many="Successfully imported %d albums."
	       count=$ImportResults.counts.albumImportSuccess
	       arg1=$ImportResults.counts.albumImportSuccess}
    {else}
      {g->text text="No albums imported."}
    {/if}
  </h2>

  {if count($ImportResults.status.albumImportSuccess) > 0}
    <ul>
      {foreach from=$status.albumImportSuccess key=albumname item=junk}
      <li>
	{g->text text="Imported %s" arg1=$albumname}
      </li>
      {/foreach}
    </ul>
  {/if}
</div>

{if count($ImportResults.status.albumImportFailure) > 0}
<div class="gbBlock">
  <h2 class="giError">
    {if ($ImportResults.counts.albumImportFailure)}
      {g->text one="Error while importing %d album." many="Errors while importing %d albums."
	       count=$ImportResults.counts.albumImportFailure
	       arg1=$ImportResults.counts.albumImportFailure}
    {/if}
  </h2>

  <ul>
    {foreach from=$ImportResults.status.albumImportFailure key=albumname item=junk}
    <li>
      {g->text text="Error importing %s" arg1=$albumname}
    </li>
    {/foreach}
  </ul>
</div>
{/if}

<div class="gbBlock">
  <a href="{g->url arg1="view=core.SiteAdmin" arg2="subView=cmmigrate.SelectCmAlbum"}">
    {g->text text="Import more data"}
  </a>
</div>
