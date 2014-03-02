package com.stericsson.sdk.brp.filesystem;

import com.stericsson.sdk.brp.AbstractCommand;
import com.stericsson.sdk.brp.CommandName;

/**
 * Remote command for copying file from the source path to the destination path
 * 
 * @author pkutac01
 * 
 */
public class CopyFile extends AbstractCommand {

    /**
     * {@inheritDoc}
     */
    @Override
    public CommandName getCommandName() {
        return CommandName.FILE_SYSTEM_COPY_FILE;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String[] getParameterNames() {
        return new String[] {
            PARAMETER_EQUIPMENT_ID, PARAMETER_SOURCE_PATH, PARAMETER_DESTINATION_PATH};
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean isCancellable() {
        return false;
    }

}